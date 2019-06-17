#include <iostream>
#include "Vector.hpp"
#include <algorithm>
using namespace std;

void TestVector2()
{
  Vector<int> v;
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(3);
  v.PushBack(4);
  v.PushBack(5);
  v.PushBack(6);
  v.PushBack(7);

  for(size_t i = 0;i<v.Size();i++)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
  Vector<int>::iterator it = v.begin();
  v.Insert(it, 0);
  Vector<int>::iterator ret = std::find(v.begin(), v.end(), 3);
  if (ret != v.end())
  {
    cout << *ret << endl;
    v.Insert(ret, 30);
    //cout << *ret << endl;
    //  
  }

  ret = std::find(v.begin(), v.end(), 3);
  v.Erase(ret);

  for (size_t i = 0;i<v.Size();i++)
  {
    cout<<v[i]<< " ";
  }
  cout << endl;
}

void TestVector4()
{
  Vector<int> v;
  v.PushBack(1);
  v.PushBack(2);
  v.PushBack(3);
  v.PushBack(4);
  v.PushBack(5);
  v.PushBack(6);
  v.PushBack(7);

  Vector<int> copy(v);
  for (auto e : v)
  {
    cout << e << " ";

  }
  cout << endl;

  for (auto e : copy)
  {
    cout << e << " ";

  }
  cout << endl;

  Vector<int> v2;
  v2.PushBack(10);
  v2.PushBack(10);
  for(auto e : v)
  {
    cout<< e << " ";
  }
  cout<<endl;
  v = v2;

  for (auto e : v)
  {
    cout << e << " ";

  }
  cout << endl;

}

int main()
{
  //TestVector2();
  TestVector4();
  return 0;
}
