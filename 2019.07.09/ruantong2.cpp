#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string str;
  char cur;
  //string arr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
  while(cin>>str)
  { 
    sort(str.begin(),str.end());
    int count = 0;
    int maxcount = 0;
    for(size_t i = 0;i<str.length();i++)
    {
      if(str[i] == str[i+1])
      {
        count++;
      }
      else
      {
        if(count > maxcount)
        {
          maxcount = count;
          cur = str[i];
        }
        count = 1;
      }
    }
    cout<<maxcount<<endl;
    cout<<cur<<endl;
  }
}
