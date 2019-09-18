#include <iostream>

using namespace std;

template<class T>
class SmartPtr
{
  public:
    SmartPtr(T* ptr = NULL)
    :_ptr(ptr)
    {}

    ~SmartPtr()
    {
      if(_ptr)
      {
        delete _ptr;
      }
    }

    T& operator*()
    {
      return *_ptr;
    }
    T* operator->()
    {
      return _ptr;
    }
  private:
    T* _ptr;
};

struct Date
{
  int _year;
  int _month;
  int _day;
};

int main()
{
  SmartPtr<int> sp(new int);
  *sp = 10;
  cout<<*sp<<endl;
  SmartPtr<Date> sparry(new Date);
  sparry->_year = 2019;
  sparry->_month = 9;
  sparry->_day = 17;
  cout<<sparry->_year<<"-"<<sparry->_month<<"-"<<sparry->_day<<endl;
  return 0;
}
