#include <iostream>
#include <string>
using namespace std;


void test_string()
{
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
}

int main()
{
  test_string();
  return 0;
}
