#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

void test()
{
  string str;
  string st;

  getline(cin, str);
  getline(cin, st);

  for (size_t i = 0; i< st.size(); i++){
    int index;

    while ((index = str.find(st[i])) != -1){//查找第一次出现该字符的位置
      str.erase(index, 1);//从index位置开始删除一个字符
    }

  }
  cout << str << endl;

}
int main(){


  test();
  return 0;

}
