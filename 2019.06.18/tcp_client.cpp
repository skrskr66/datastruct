#include "tcpsocket.hpp"

int main(int argc,char* argv[])
{
  if(argc != 3)
  {
    cout<<"./tcp_client ip port"<<endl;
    return -1;
  }
  string ip = argv[1];
  uint16_t port = atoi(argv[2]);
  //字符串转换成整型数的一个函数
  TcpSocket sock;
  CHECK_RET(sock.Socket());
  CHECK_RET(sock.Connect(ip,port));
  
  while(1)
  {
    cal info;
    cin>>info.num1>>info.op>>info.num2;
    int fd = sock.GetSockFd();
    send(fd,&info,sizeof(cal),0);
  }
  sock.Close();
  return 0;
}
