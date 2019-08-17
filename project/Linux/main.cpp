#include "client.hpp"
#include "server.hpp"

void srv_start()
{
  P2PServer server;
  server.Start(12345);
}

int main()
{
  std::thread thr(srv_start);
  thr.detach();
  P2PClient client(12345);
  client.Start();
  return 0;
}
