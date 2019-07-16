//对字符串中的所有单词进行倒排。
//说明：
//1、每个单词是以26个大写或小写英文字母构成；
//2、非构成单词的字符均视为单词间隔符；
//3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
//4、每个单词最长20个字母；
//
//输入描述:
//输入一行以空格来分隔的句子
//输出描述:
//输出句子的逆序
//
//示例1
//输入
//I am a student
//输出
//student a am I

#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
  string str;
  while (getline(cin, str))
  {
    string cur;
    string _tmp;
    reverse(str.begin(), str.end());
    string::iterator it = str.begin();
    while (it != str.end())
    {
      if ((('a' <= *it && *it <= 'z') || ('A' <= *it && *it <= 'Z')) && (*it) != ' ')
      {
        cur += *it;
        it++;
      }
      else
      {
        it++;
        string tmp;
        tmp += cur;
        reverse(tmp.begin(), tmp.end());
        tmp += ' ';
        _tmp += tmp;
        string temp;
        cur.swap(temp);
      }
      if (it == str.end())
      {
        string tmp;
        tmp += cur;
        reverse(tmp.begin(), tmp.end());
        //tmp += ' ';
        _tmp += tmp;
        string temp;
        cur.swap(temp);
      }
    }
    for (auto t : _tmp)
    {
      cout << t;
    }
  }
  return 0;
}
