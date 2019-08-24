#include <iostream>
using namespace std;
int main()
{
  int v =1;
  int *p = &v;
  int *&r = p;
  (*r)++;
  cout<<r<<" "<<*r<<endl;
}
