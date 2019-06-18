#include "tcpsocket.hpp"

int main(int argc,char* argv[])
{
  if(argc != 3)
  {
    cout<<"./tcp_server ip port"<<endl;
    return -1;
  }
  string ip = argv[1];
  uint16_t port = atoi(argv[2]);

  TcpSocket sock;
  CHECK_RET(sock.Socket());
  CHECK_RET(sock.Bind(ip,port));
  CHECK_RET(sock.Listen());

  while(1)
  {
    TcpSocket clisock;
    struct sockaddr_in cliaddr;

    if(sock.Accept(clisock,&cliaddr) == false)
    {
      continue;
    }
    cout<<"new connect client:"<<inet_ntoa(cliaddr.sin_addr)<<":"<<ntohs(cliaddr.sin_port)<<endl;
    
    int fd = clisock.GetSockFd();
    cal info;

    recv(fd,&info,sizeof(cal),0);
    switch(info.op)
    {
      case '+':
        cout<<"num1:"<<info.num1<<info.op<<"num2:"<<info.num2<<"="<<info.num1 + info.num2<<endl;
        break;
      case '-':
        cout<<"num1:"<<info.num1<<info.op<<"num2:"<<info.num2<<"="<<info.num1 - info.num2<<endl;
        break;
      case '*':
        cout<<"num1:"<<info.num1<<info.op<<"num2:"<<info.num2<<"="<<info.num1 * info.num2<<endl;
        break;
      case '/':
        cout<<"num1:"<<info.num1<<info.op<<"num2:"<<info.num2<<"="<<info.num1 / info.num2<<endl;
        break;
    }
  }
  sock.Close();
}
