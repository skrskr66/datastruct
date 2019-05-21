#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


void test_string()
{
 /*
  std::string s1("hello");
  std::string::iterator it1 = s1.begin();
  std::string::iterator it2 = s1.end() - 1;
  cout<<*it2<<endl;
  while (it1 != s1.end())
  {
    ++(*it1);
    cout << *it1 << " ";
    it1++;

  }
  cout << endl;
  */

  string s1("hello");
/*
  string s2(s1);
  string s3 = s1;
  cout<<s1<<endl;
  cout<<s2<<endl;
  cout<<s3<<endl;
  string s4("world");
  s1 = s4;
  cout<< s1 <<endl;
  s1[4] = 'x';
  for(size_t i = 0;i<s1.size();++i)
  {
    cout<<s1[i]<<endl;
    cout<<s1.at(i)<<endl;
  }
  cout<<endl;
  */

  //正向迭代器
  string::reverse_iterator rit1 = s1.rbegin();
  while(rit1 != s1.rend())
  {
    cout<<*rit1<<" ";
    ++rit1;
  }
  cout<<endl;

  const string s5("122333");
  string::const_iterator it5 = s5.begin();
  while(it5 != s5.end())
  {
    cout<<*it5<<" ";
    it5++;
  }
  cout<<endl;

  //for(const auto& ch : s5)
  //{
  //  cout<<ch<<" ";
  //}
  //cout<<endl;
  

}

void test_string2()
{
  string s1("world");
  s1.insert(s1.begin(),' ');
  s1.insert(0,"hello");
  cout<<s1<<endl;

  string::iterator it1 = s1.begin();
  while(it1 != s1.end())
  {
    if(*it1 == ' ')
    {
      s1.erase(it1);
    }
    ++it1;
  }
  cout<< s1 <<endl;

  string file1("string.cpp.gz");
  size_t pos = file1.rfind('.');
  string suffix = file1.substr(pos,5);
  cout<<suffix<<endl;

  string url1("http://www.cplusplus.com/reference/string/string/find/");
  size_t start = url1.find("://");//7
  start += 3;
  size_t finish = url1.find('/',start);//24
  string address = url1.substr(start,finish-start);//从当前字符往后多少长度
  cout<<address<<endl;
  cout<<url1<<endl;
}

void test_string3()
{ 
  string str1;
  cin>>str1;
  cout<<str1<<endl;

  string str2;
  cin>>str2;
  cout<<str2<<endl;

  cout<<(str1 < str2)<<endl;
  cout<<(str1 == str2)<<endl;

  cout<<str1 + "111"<<endl;
  cout<<"2222" + str1<<endl;
}

void test_string4()
{
  string s;
  getline(cin,s);
  reverse(s.begin(),s.end());
  //cout<<s<<endl;
  string::iterator start = s.begin();
  //cout<<*start<<endl;
  string::iterator end = s.end();
  while(*start != *end)
  {
    string::iterator end_word = start;
    while(end_word != end && *end_word != ' ')
    {
      ++end_word;
    }
    //cout<<*end_word<<endl;打印验证此时在空白' '处
      reverse(start,end_word);
      if(end_word != end)
      {
        start = end_word + 1;
      }
      else
      {
        start = end_word;
      }
    
  }
  cout<<s<<endl;
}

int main()
{
  test_string4();
  return 0;
}
