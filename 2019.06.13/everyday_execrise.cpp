//找出字符串中第一个只出现一次的字符


#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str;
  size_t i =0;
  while(cin>>str)
  {
    for(i =0;i<str.size();i++)
    {
      if(str.find(str[i]) == str.rfind(str[i]))
      {
        cout<<str[i]<<endl;
        break;

      }

    }
    if(str.size() == i)
    {
      cout<<-1<<endl;

    }

  }
  return 0;

}
