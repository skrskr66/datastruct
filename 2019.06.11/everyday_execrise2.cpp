//计算两个字符串的最大公共字串的长度，字符不区分大小写
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str1;
  string str2;
  //用短串进行截断
  string cur;

  if(str1.length() > str2.length())
  {
    str1.swap(str2);
  }
  while(cin>>str1>>str2)
  {
    for(size_t i = 0;i<str1.length();i++)
    {
      for(size_t j = 0;j<str1.length() - i;j++)
      {
        string sub = str1.substr(j,i);
        if(str2.find(sub) != string::npos)
        {
          cur = sub;
          break;
        }
      }
    }
  }
  return 0;
}
