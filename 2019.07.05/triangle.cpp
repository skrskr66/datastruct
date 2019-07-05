#include <iostream>
#include <string>
#define ADD(x,y) ((x)+(y))
#define CMP(x,y) ((x)>(y))

int main()
{
  double a,b,c;
  while(std::cin>>a>>b>>c)
  {
    if(CMP(ADD(a,b),c) && CMP(ADD(a,c),b) && CMP(ADD(b,c),a))
    {
      std::cout<<"Yes"<<std::endl;
    }
    else
    {
      std::cout<<"No"<<std::endl;
    }
  }
  return 0;
}
