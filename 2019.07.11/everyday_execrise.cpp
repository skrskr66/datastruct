//一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。
//对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？
//
//输入描述:
//输入包含多组数据。
//每组数据包含两个字符串s,t，分别是成对出现的花布条和小饰条，其布条都是用可见ASCII字符表示的，
//可见的ASCII字符有多少个，布条的花纹也有多少种花样。花纹条和小饰条不会超过1000个字符长。
//
//
//输出描述:
//对应每组输入，输出能从花纹布中剪出的最多小饰条个数，如果一块都没有，那就输出0，每个结果占一行。
//示例1
//
//输入
//abcde a3
//aaaaaa aa
//输出
//0
//3
//
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str, cur, str1;
  while (cin >> str >> cur)
  {
    int count = 0;
    while(str.find(cur) != string::npos)
    {
      int ret = str.find(cur);
      str1 = str.substr(ret + cur.size(), str.size());
      count++;
      str = str1;
    }
    cout << count << endl;
  }
  return 0;
}
