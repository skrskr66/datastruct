#define SHARED_DIR "shared"
#include "httplib.h"
using  namespace httplib;
class P2PServer
{
private:
  httplib::Server srv;
public:
  /*附近主机配对请求处理*/
  static void PairHandler(const Request& req, Response& res);
  /*文件列表请求处理*/
  static void ListHandler(const Request& req, Response& res);
  /*文件下载请求处理*/
  static void DownloadHandler(const Request& req, Response& res);

};
