#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string s1,s2;
  while(cin>>s1>>s2)
  {
    string str;
    int cur = 0;
    int i = s1.size()-1,j = s2.size()-1;
    while(i >= 0 || j >= 0 || cur != 0)
    {
      if(i >= 0)
        cur += (s1[i--] - '0');
      if(j >= 0)
        cur += (s2[j--] - '0');
      str += to_string(cur % 10);
      cur /= 10;
    }
    reverse(str.begin(),str.end());
    cout<<str<<endl;
  }
  return 0;
}
