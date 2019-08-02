#define DOWNLOAD_DIR "download"
#define RANGE_SIZE (10 << 20)
#include "httplib.h"
using namespace httplib;
class P2pClient
{
  private:
    std::vector<std::string> _host_list;
    std::vector<std::string> _file_list;
  private:
    bool GetHostList(std::vector<std::string> &list);
    int64_t GetFileSize(int file_id);
  public:
    int SelectShow(); //用户选择显示
    bool PairNearbyHost(); //附近主机匹配
    bool ShowNearByHost(); //显示附近主机
    bool GetShareList(int host_id); //获取指定主机的共享文件列表
    bool ShowShareList(); //显示指定主机的共享文件列表
    bool DownLoadFile(int file_id); //下载指定主机的共享文件
};
