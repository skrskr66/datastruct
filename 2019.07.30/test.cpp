#include <iostream>

using namespace std;

class ABC
{
public:
  void A(int aa,int bb)
  {
     a = aa--;
     b = a*bb;
  }
  int a;
  int b;
};

int main()
{
  ABC Aa;
  Aa.A(4,5);
  cout<<Aa.a;
  return 0;
}
