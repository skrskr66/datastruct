#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void test()
{
  string str;
  //str.resize(100);
  getline(cin, str);
  int index = 0;
  while ((index = str.find(' ')) != -1)
  {
    str.erase(index, 1);

  }
  int k = ((str.size()) / 2) - 1;
  sort(str.begin(),str.end());
  cout << str[k] << endl;
}

void test2()
{

  string str,cur_char,src_char;
  getline(cin,str);

  for(size_t i = 0;i <= str.size();++i)
  {
    if(str[i] > 47 && str[i] < 58)
    {
      cur_char += str[i];

    }
    else
    {
      if(cur_char.length() > src_char.length())
      {
        src_char = cur_char;

      }
      cur_char = "";

    }

  }
  cout<<src_char<<endl;

}
int main()
{
  test2();
  return 0 ;
}
