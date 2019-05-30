#include <iostream>
#include <stdio.h>
using namespace std;
struct A
{
  void foo(){printf("foo");}
  virtual void bar(){printf("bar");}
  A(){bar();}
};

struct B:A
{
  void foo(){printf("b_foo");}
  void bar(){printf("b_bar");}
};


int main()
{
  A *p = new B;
  p->foo();
  p->bar();
  return 0;
}


//#include <stdio.h>
//
//int func(int x)
//{
//  int count = 0;
//  while(x)
//  {
//    count++;
//    x=x&(x-1);
//  }
//  return count;
//}
//
//int main()
//{
//  func(9999);
//  printf("****\n");
//  printf("%d",func(9999));
//  return 0;
//}
