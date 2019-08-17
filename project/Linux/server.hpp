//客户端配对请求
//请求： GET /hostpair HTTP/1.1 /hostpair
//响应： HTTP/1.1 200 OK
//客户端文件列表获取请求
//请求： GET /list/ HTTP/1.1 /(list/){0,1}
//响应：
// HTTP/1.1 200 OK
// Content-Length: len
// 
// filename1\n
// filename2\n
// ...
//客户端文件分块下载请求
//  请求：
//GET /list/filename HTTP/1.1 /list/(.*)
//  Range: byte=range_start-range_end
//  响应：
//  HTTP/1.1 200 OK
//  Content-Length: range_size
//  range_data
//
#include <iostream>
#include <boost/filesystem.hpp>
#include <stdio.h>
#include <fstream>
#include "httplib.h"
#define SHARED_DIR "share"

using namespace httplib;
namespace bf = boost::filesystem;
class P2PServer
{
  private:
    Server _server;
  private:
    /*附近主机配对请求处理*/
    static void GetHostPair(const Request& req, Response& rsp)
    {
      rsp.status = 200; 
    }
    /*文件列表请求处理*/
    static void GetFileList(const Request& req, Response& rsp)
    {
      bf::directory_iterator item_begin(SHARED_DIR);
      bf::directory_iterator item_end;
      //std::string body;
      for(;item_begin != item_end;++item_begin)
      {
        if(bf::is_directory(item_begin->status()))
        {
          continue;
        }
        bf::path path = item_begin->path();
        std::string name = path.filename().string();
        rsp.body += name + '\n';
      }
      //res.set_header("Content-Type","text/html");
      rsp.status = 200;
    }
    /*文件下载请求处理*/
    static void GetFileData(const Request& req, Response& rsp)
    {
      bf::path path(req.path);
      std::stringstream name;
      name<<SHARED_DIR << "/" << path.filename().string();
      if(!bf::exists(name.str()))
      {
        rsp.status = 404;
        return;
      }
      if(bf::is_directory(name.str()))
      {
        rsp.status = 403;
        return;
      }
      int64_t fsize = bf::file_size(name.str());
      if(req.method == "HEAD")
      {
        rsp.status = 200;
        std::string len = std::to_string(fsize);
        rsp.set_header("Content-Length",len.c_str());
        return;
      }
      else
      {
        if(!req.has_header("Range"))
        {
          rsp.status = 400;
          return;
        }
        std::string range_val;
        range_val = req.get_header_value("Range");
        int64_t start,rlen;
        bool ret = RangeParse(range_val,start,rlen);
        if(ret == false)
        {
          rsp.status = 400;
          return;
        }
        std::ifstream file(name.str(),std::ios::binary);
        if(!file.is_open())
        {
          std::cerr<<"open file" << name.str() <<" failed\n";
          rsp.status = 404;
          return;
        }
        file.seekg(start,std::ios::beg);
        rsp.body.resize(rlen);
        file.read(&rsp.body[0],rlen);
        if(!file.good())
        {
          std::cerr<<"read file "<< name.str() << " body error";
          rsp.status = 500;
          return;
        }
        file.close();
        rsp.status = 206;
        rsp.set_header("Content-Type","application/octet-stream");
        std::cerr<<"file range:"<<range_val<<"download success\n";
      }
    }
    static bool RangeParse(std::string &range_val,int64_t &start,int64_t &len)
    {
      size_t pos1 = range_val.find("=");
      size_t pos2 = range_val.find("-");
      std::cout<<pos1<<"  "<<pos2<<"\n";
      std::cout<<range_val<<"\n";
      if((pos1 == std::string::npos) || (pos2 == std::string::npos))
      {
        std::cerr <<"range"<<range_val<<"format error\n";
        return false;
      }
      int64_t end;
      std::string _rstart;
      std::string _rend;
      _rstart = range_val.substr(pos1+1,pos2-pos1-1);
      _rend = range_val.substr(pos2+1);
      std::stringstream tmp;
      tmp <<_rstart;
      tmp>>start;
      tmp.clear();
      tmp<<_rend;
      tmp>>end;
      len = end-start+1;
      return true;
    }
  public:
    P2PServer()
    {
      if(!bf::exists(SHARED_DIR))
      {
        bf::create_directory(SHARED_DIR);//当文件目录不存在时，直接创建
      }
    }
    bool Start(uint16_t port)
    {
      _server.Get("/hostpair",GetHostPair);
      _server.Get("/list",GetFileList);
      _server.Get("/list/(.*)",GetFileData);
      _server.listen("0.0.0.0",port);
    }
};
