#include <iostream>
#include "List.cpp"

using namespace std;
void test()
{
  List<int> l;
  l.PushBack(1);
  l.PushBack(2);
  l.PushBack(3);

  List<int>::iterator it = l.begin();
  while(it != l.end())
  {
    cout<<*it<<" ";
    ++it;
  }
}


int main()
{
  test();
  return 0;
}
