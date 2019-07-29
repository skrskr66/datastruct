//nowcoder要和朋友交流一些敏感的信息，例如他的电话号码等。因此他要对这些敏感信息进行混淆，比如在数字中间掺入一些额外的符号，让它看起来像一堆乱码。
//现在请你帮忙开发一款程序，解析从nowcoder那儿接收到的信息，读取出中间有用的信息。
//
//输入描述:
//输入有多行。
//
//每一行有一段经过加密的信息（其中可能包含空格），并且原始信息长度不确定。
//
//
//输出描述:
//输出每段信息中数字信息。
//示例1
//输入
//$Ts!47&*s456  a23* +B9k
//输出
//47456239

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  string cur("0123456789");
  while(getline(cin,str))
  {
    string strs;
    for(size_t i = 0;i < str.size();i++)
    {
      if(cur.find(str[i]) != string::npos)
      {
        cout<<str[i];
      }
    }
    cout<<endl;
  }
  return 0;
}
