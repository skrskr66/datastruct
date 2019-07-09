#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  string cur;
  while(cin>>str>>cur)
  {
    size_t pos = str.find(cur,0);
    cout<<pos + 1<<endl;
  }
}
