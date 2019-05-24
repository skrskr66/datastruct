#include <iostream>
#include <string>
#include <vector>
using namespace std;
void test_string() // 10%用例
{
  string str1;
  string str2;
  string cur;
  int i = 0,j = 0,count=0,tmp=0;
  getline(cin, str1);
  getline(cin, str2);
  string::iterator it = str1.begin();
  if(str1.size() < 100 && str2.size() < 100){
  while (it != str1.end())
  {
    it++;
    cur = str1.insert(i, str2);
    i++;
    if (i > str1.size())
    {
      break;
    }
    string::iterator cur_start = cur.begin();
    string::iterator cur_end = cur.end() - 1;
    while (*cur_start == *cur_end)
    {
      *cur_start++;
      *cur_end--;
      if (count > (cur.size() / 2))
      {
        count -= 1;
        break;
      }
      count++;
      if(*cur_start != *cur_end)
      {
        count = 0;
        break;
      }

    }
    if (count == (cur.size() / 2) && (cur.size() % 2 == 0))
    {
      tmp++;  
    }
    cur = str1.erase(j, 1);
    j++;
    cur = "";
  }
  cout << tmp;
  }
}



int main()
{
  test_string(); 
  return 0;
}
