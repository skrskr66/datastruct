//NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间会用一个逗号和空格隔开；
//如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
//现在给你一组收件人姓名，请你帮他生成相应的收件人列表。
//
//输入
//3
//Joe
//Quan, William
//Letendre,Bruce
//2
//Leon
//Kewell
//输出
//Joe, "Quan, William", "Letendre,Bruce"
//Leon, Kewell
#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n;
  while(cin>>n)
  {
    cin.get();
    string name;
    for(int i = 0;i < n;i++)
    {
      getline(cin,name);
      if(i != n - 1)
      {
        if(name.find(',') != string::npos || name.find(' ') != string::npos)
        {
          cout<<'\"'<<name<<'\"'<<','<<' ';
        }
        else
        {
          cout<<name<<','<<' ';
        }
      }
      else
      {
        if(name.find(',') != string::npos || name.find(' ') != string::npos)
        {
          cout<<'\"'<<name<<'\"'<<endl;
        }
        else
        {
          cout<<name<<endl;
        }
      }
    }
  }
  return 0;
}
