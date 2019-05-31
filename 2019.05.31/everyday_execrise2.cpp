#include<iostream>
using namespace std;
int main()
{
  int byte;
  while(cin>>byte)
  {
    int k=0;
    for( k=0;byte!=0;k++ )
    {
      byte=byte&(byte<<1);

    }
    cout<<k<<endl;

  }
  return 0;

}
