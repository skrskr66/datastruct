#include<iostream>
#include <string>
using namespace std;

class skr
{
  public:
    void fun()
    {
      cout << "Do you have freestyle?" << endl;
    }
};
class cxk : public skr
{
  public:
    void fun(int i)
    {
      skr::fun();
      cout << "I like singsing dance rap and basketball" <<i<<endl;
    }
};
void Test()
{
  cxk b;
  skr a;
  a.skr::fun();
  b.fun(10);
  b.skr::fun();
};

int main()
{
  Test();
  return 0;
}
