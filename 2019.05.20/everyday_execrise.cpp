#include <iostream>                   
#include <string>
#include <vector>
#include <algorithm> 
using namespace std; 

void test_string()
{
  string str1;
  string str2;

  getline(cin,str1);
  getline(cin,str2);

  for(size_t i = 0;i<str2.size();++i)
  {
    int index;
    while((index = str1.find(str2[i])) != -1)
    {
      str1.erase(index,1);//删除失败时返回-1 
    }
  }
  cout<<str1<<endl;
}

int main()
{
  test_string();
  return 0;
}
