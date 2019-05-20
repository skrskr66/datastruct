#include <iostream>
using namespace std;
template<class T>
T Add(T left, T right)
{
  return left + right;
}

template<class T1, class T2>
T1 Add(T1 left, T2 right)
{
  return left + right;
}

int main()
{
  cout<<Add(1,2)<<endl;
  cout<<Add(1,2.0)<<endl;

  return 0;
}
