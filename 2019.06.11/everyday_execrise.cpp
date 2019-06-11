//输入一个字符串，然后反转这个字符串

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string str;
  string cur;
  while(cin>>str)
  {
    reverse(str.begin(),str.end());
    cout<<str<<endl;
  }
}
