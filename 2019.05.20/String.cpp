#include <string>
#include <iostream>

using namespace std;

void string_test1()
{
  string s1;
  cout<< s1 <<endl;
  cout<< s1.c_str()<<endl;

  string s2("hello world");
  cout<<s2<<endl;
  cout<<s2.c_str()<<endl;

  string s3(10,'M');
  cout<<s3<<endl;

  string s4(s3);
  cout<<s4<<endl;

  string s5(s2,2,7);//从字符串第几个到第几个，然后截取
  cout<<s5<<endl;
}

void string_test2(){
  string s("hello");
  s.push_back(' ');
  s.append("world");
  cout<<s<<endl;

  string w("world");
  s += '-';
  s += "change ";
  s += w;
  cout<<s<<endl;
}

void string_test3()
{

 /* string s("hello"); 
  cout<<s.size()<<endl;//不加'\0'
  cout<<s.max_size()<<endl;//废物接口，没啥用
  cout<<s.length()<<endl;//不加'\0'

  s += "xxxxxxxxxxxxxxxxxxxxxxxx";
  cout<<s.size()<<endl;
  cout<<s.capacity()<<endl;
  s.clear();//清空字符串
  cout<<s<<endl;
  cout<<s.size()<<endl;//大小此时为0
  cout<<s.capacity()<<endl;//但是容量保存依旧为之前的29
*/
  
/*  string s("hello");
  s.resize(13);//在当前字符数字之后插入'\0'，来扩展当前内容以达到n的大小
  s.resize(20,'a');
  cout<<s<<endl;
  cout<<s.c_str()<<endl;//返回一个字符串，到'\0'
  cout<<s.size()<<endl;
  cout<<s.capacity()<<endl;
*/
/*
  string s("hello");
  s.reserve(10);
  s.reserve(20);//更改为最多n个字符的长度
  cout<<s<<endl;
  cout<<s.size()<<endl;
  cout<<s.capacity()<<endl;
*/

  string s;
  //s.reserve(1000);
  s.resize(1000);
  size_t sz = s.capacity();
  cout<<"capacity change:"<<sz<<'\n';
  cout<<"makeing s grow:\n";
  for(int i = 0;i < 1000;++i)
  {
    //s += 'c';
    s[i] = 'c';
    if(sz != s.capacity())
    {
      sz = s.capacity();
      cout<<"capacity changed:"<<sz <<'\n';
    }
  }
}


int main()
{
  string_test3();
  return 0;
}
