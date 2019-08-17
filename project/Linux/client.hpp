#include "httplib.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
#include <unistd.h>
#include <fcntl.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <boost/filesystem.hpp>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>
#define DOWNLOAD_DIR "Download/"
#define RANGE_SIZE 10000
using namespace httplib;
namespace bf = boost::filesystem;
class P2PClient
{
  private:
    u_int16_t _srv_port;
    int _host_idx;
    std::vector<std::string> _host_list;
    std::vector<std::string> _file_list;

  private:  
    bool GetHostList(std::vector<std::string> &list)
    {
      struct ifaddrs *addrs = NULL;
      struct sockaddr_in *ip = NULL;
      struct sockaddr_in *mask = NULL;
      getifaddrs(&addrs);
      for(;addrs != NULL;addrs = addrs->ifa_next)
      {
        ip = (struct sockaddr_in*)addrs->ifa_addr;
        mask = (struct sockaddr_in*)addrs->ifa_netmask;
        if(ip->sin_family != AF_INET)
        {
          continue;
        }
        if(ip->sin_addr.s_addr == inet_addr("127.0.0.1"))
        {
          continue;
        }
        uint32_t net,host;
        net = ntohl(ip->sin_addr.s_addr & mask->sin_addr.s_addr);
        host = ntohl(~mask->sin_addr.s_addr);
        for(int i = 2;i < host - 1;i++)
        {
          struct in_addr ip;
          ip.s_addr = htonl(net + i);
          list.push_back(inet_ntoa(ip));
        }
      }
      freeifaddrs(addrs);//必须要释放
      return true;
    }//得到所有主机列表

    int SelectShow()
    {
      std::cout<<"1、搜索附近主机"<<std::endl;
      std::cout<<"2、显示在线主机"<<std::endl;
      std::cout<<"3、显示文件列表"<<std::endl;
      std::cout<<"0、退出"<<std::endl;
      int choose;
      std::cout<<"请选择：";
      fflush(stdout);
      std::cin>>choose;
      return choose;
    }//用户选择显示

    void HostPair(std::string &i)
    {
      Client client(&i[0],_srv_port);
      auto res = client.Get("/hostpair");
      if(res && res->status == 200)
      {
        std::cerr<<"host "<<i<<" pair success"<<std::endl;
        _host_list.push_back(i);
      }
      std::cerr<<"host "<<i<<" pair failed"<<std::endl;
      return;
    }

    bool PairNearbyHost(std::vector<std::string> &list)
    {
      _host_list.clear();
      std::vector<std::thread> thr_list(list.size());
      for(size_t i = 0;i < list.size();i++)
      {
        std::thread thr(&P2PClient::HostPair,this,std::ref(list[i]));
        thr_list[i] = std::move(thr);
      }
      for(size_t i = 0;i < thr_list.size();i++)
      {
        thr_list[i].join();
      }
      return true;
    }//附近主机匹配

    bool ShowNearByHost()
    {
      for(size_t i = 0;i < _host_list.size();i++)
      {
        std::cout<<i<<"."<<_host_list[i]<<std::endl;
      }
      std::cout<<"请选择：";
      fflush(stdout);
      std::cin>>_host_idx;
      if(_host_idx < 0 || (_host_idx > _host_list.size()))
      {
        _host_idx = -1;
        std::cerr<<"请好好选择"<<std::endl;
        return false;
      }
      return true;
    }//显示附近主机

    bool GetFileList()
    {
      Client client(_host_list[_host_idx].c_str(),_srv_port);
      auto res = client.Get("/list");
      if(res && res->status == 200)
      {
        boost::split(_file_list,res->body,boost::is_any_of("\n"));
      }
      return true;
    }//获取指定主机的共享文件列表

    bool ShowShareList(std::string &name)
    {
      for(size_t i = 0;i < _file_list.size();i++)
      {
        std::cout<<i<<"."<<_file_list[i]<<"\n";
      }
      std::cout<<"请再次选择：";
      fflush(stdout);
      size_t file_idx;
      std::cin >> file_idx;
      if(file_idx < 0 || file_idx > _file_list.size())
      {
        std::cerr << "请好好选择"<<std::endl;
        return false;
      }
      name = _file_list[file_idx];
      return true;
    }//显示指定主机的共享文件列表

    void RangeDownload(std::string host,std::string name,int64_t start,int64_t end,int *res)
    {
      std::string uri = "/list/" + name;
      std::string realpath = DOWNLOAD_DIR + name;
      std::stringstream range_val;
      range_val << "bytes=" << start <<"-"<<end;
      std::cerr<<"download range:"<<range_val.str()<<"\n";
      *res = 0;
      Client client(host.c_str(),_srv_port);
      Headers header;
      header.insert(std::make_pair("Range",range_val.str().c_str()));
      
      auto rsp = client.Get(uri.c_str(),header);
      
      std::cerr<<rsp->status<<"\n";
      if(rsp && rsp->status == 206)
      {
        std::cerr<<"open file"<< realpath<<std::endl;
        int fd = open(realpath.c_str(),O_CREAT|O_WRONLY,0664);
        if(fd < 0)
        {
          std::cerr<<"file"<<realpath<<"open error\n";
          return;
        }
        lseek(fd,start,SEEK_SET);
        int ret = write(fd,&rsp->body[0],rsp->body.size());
        if(ret < 0)
        {
          std::cerr<<"file"<<realpath<<"write error\n";
          close(fd);
          return;
        }
        close(fd);
        *res = 1;
        std::cerr<<"file"<<realpath<<"download range:"<<range_val.str()<<" success\n";
      }
      return;
    }

    int64_t GetFileSize(std::string &host,std::string &name)
    {
      int64_t fsize = -1;
      std::string path = "/list/" + name;
      Client client(host.c_str(),_srv_port);
      auto res = client.Head(path.c_str());
      if(res && res->status == 200)
      {
        if(!res->has_header("Content-Length"))
        {
          return -1;
        }
        std::string len = res->get_header_value("Content-Length");
        std::stringstream tmp;
        tmp << len;
        tmp >> fsize;
      }
      return fsize;
    }

    bool DownLoadFile(std::string &name)
    {
      //Get /list/filename HTTP1.1
      //HTTP/1.1 200 OK
      //Content-Length:fsize
      //FILE
      std::string host = _host_list[_host_idx];
      int64_t fsize = GetFileSize(host,name);
      if(fsize<0)
      {
        std::cerr<<"download file"<<name<<"failed\n";
        return false;
      }
      int count = fsize/RANGE_SIZE;//(文件大小/分块大小)
      std::vector<boost::thread> thr_list(count + 1);
      std::vector<int> res_list(count + 1);
      for(int64_t i = 0;i <= count;i++)
      {
        int64_t start,end,rlen;
        start =(int64_t)i*RANGE_SIZE;
        end = (i+1)*RANGE_SIZE - 1;
        if(i == count)
        {
          if((fsize % RANGE_SIZE) == 0)
          {
            break;
          }
          end = fsize - 1;
        }
        rlen = end - start + 1;
        int *res = &res_list[i];
        boost::thread thr(&P2PClient::RangeDownload,this,host,name,start,end,res);
        thr_list[i] = std::move(thr);
      }
      bool ret = true;
      for(int i = 0;i <=count;i++)
      {
        if(i==count && (fsize % RANGE_SIZE == 0))
        {
          break;
        }
        thr_list[i].join();
        if(res_list[i] == 0)
        {
          ret = false;
        }
      }
      if(ret == true)
      {
        std::cerr <<"download file "<<name <<" success\n";
      }
      else
      {
        std::cerr <<"download file "<<name <<" failed\n";
        return false;
      }
      return true;
    }//下载指定主机的共享文件
public:
    P2PClient(uint16_t port)
      :_srv_port(port)
    {}
    bool Start()
    {
      while(1)
      {
        int choose = SelectShow();
        std::vector<std::string> list;
        std::string filename;
        switch(choose)
        {
          case 1:
            GetHostList(list);
            PairNearbyHost(list);
            break;
          case 2:
            if(ShowNearByHost() == false)
            {
              break;
            }
            GetFileList();
            break;
          case 3:
            if(ShowShareList(filename) == false)
            {
              break;
            }
            DownLoadFile(filename);
            break;
          case 0: 
            exit(0);
          default:
            break;
        }
      }
    }
};

