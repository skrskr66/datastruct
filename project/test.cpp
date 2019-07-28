#include <iostream>
#include "httplib.h"

static void HelloWorld(const httplib::Request &req,httplib::Response &res)
{
  res.set_content("<html><body>Hello World</body></html>","text/html");
  return;
}

int main()
{
  httplib::Server srv;
  srv.set_base_dir("./www");
  srv.Get("/",HelloWorld);
  srv.listen("47.102.46.57",9000);
  return 0;
}
