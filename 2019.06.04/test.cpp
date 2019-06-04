#include <iostream>
#include <assert.h>
using namespace std;
template<class T>
class Vector
{
  public:
    Vector(size_t capacity = 10)
      :_pData(new T[capacity])
       ,_size(0)
       ,_capacity(capacity)
  {


  }
    void PushBack(const T& data)
    {
      _pData[_size++] = data;

    }

    void PopBack()
    {
      --_size;

    }

    size_t Size()
    {
      return _size;

    }

    T& operator[](size_t pos)
    {
      assert(pos < _size);
      return _pData[pos];

    }
    ~Vector()
    {
      if(_pData)
      {
        delete[] _pData;

      }

    }
  private:
    T* _pData;
    size_t _size;
    size_t _capacity;

};
int main()
{
  Vector<int> s1;
  s1.PushBack(1);
  s1.PushBack(2);
  s1.PushBack(3);
  Vector<double> s2;
  s2.PushBack(1.0);
  s2.PushBack(2.0);
  s2.PushBack(3.0);
  for(size_t i = 0; i < s1.Size(); ++i)
  {
    cout<<s1[i]<<" ";

  }
  cout<<endl;
  for(size_t i = 0; i < s2.Size(); ++i)
  {
    cout<<s2[i]<<" ";

  }
  cout<<endl;
  return 0;
}
