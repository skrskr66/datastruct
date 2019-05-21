#include <iostream> 
#include <string>
#include <vector>
#include <algorithm> 
using namespace std; 



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
