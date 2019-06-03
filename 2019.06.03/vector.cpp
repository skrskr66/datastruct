#include <iostream>
#include <string>
#include <vector>

using namespace std;

//template<class T>
//class vector
//{
//  private:
//    T* array;
//    size_t _size;
//    size_t _capacity;
//};
int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.insert(v.begin(),0);
  for(int i=0;i < v.size();i++)
  {
    cout<<v[i]<<" ";
  }
  //size_t sz;
  //vector<int>foo;
  //foo.resize(29);
  ////foo.resize(29);
  //sz = foo.capacity();
  //cout<< "making foo grow "<<endl;
  //for(int i = 0;i<100;i++)
  //{
  //  foo.push_back(i);
  //  if(sz != foo.capacity())
  //  {
  //    sz = foo.capacity();
  //    cout<<"capacity change:"<<sz<<endl;
  //  }
  //}

  //vector<int> v;
  //v.push_back(1);
  //v.push_back(2);
  //v.push_back(3);
  //v.push_back(4);
  //v.push_back(5);
  //for(size_t i = 0;i < v.size();i++)
  //{
  //  cout<<v[i]<<" ";
  //}
  //cout<<endl;
  //vector<int>::iterator it = v.begin();
  //while(it != v.end())
  //{
  //  cout<<*it<<" ";
  //  ++it;
  //}
  //cout<<endl;
  //vector<int>::reverse_iterator it1 = v.rbegin();
  //while(it1 != v.rend())
  //{
  //  cout<<*it1<<" ";
  //  *it1++;
  //}
  //cout<<endl;
  return 0;
}
