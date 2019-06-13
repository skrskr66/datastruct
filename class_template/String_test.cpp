#include <iostream>
#include <string>
#include <string.h>
#include "String.hpp"
using namespace std;

void test1()
{
  String str("hello");
  cout<<str.c_str()<<endl;
}

int main()
{
  test1();
  return 0;
}
