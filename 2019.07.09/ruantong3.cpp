#include <iostream>
#include <string>

using namespace std;

int main()
{
  string res,str;
  int n;
  cin>>n;
  while(n)
  {
    cin>>str;
    res+=str;
    n--;
    if(n > 0)
      res+=":";
  }
  cout<<res<<endl;
}
