#include <iostream>

using namespace std;

int main()
{
  float num1,num2;
  while(cin>>num1>>num2)
  {
    float ret = num2 * 2 * 3.14;
    if(ret > num1)
    {
      cout<<"Yes"<<endl;
    }
    else 
    {
      cout<<"No"<<endl;
    }
  }
  return 0;
}
