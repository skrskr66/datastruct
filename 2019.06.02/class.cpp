#include <iostream>
#include <stdlib.h>
using namespace std;

class Array
{
  public:
    Array(int size)
      :_size(10)
      ,_array((int*)malloc(sizeof(int)*_size))
  {
    cout<<sizeof(_size)<<endl;
  }
  private:
    int* _array;
    int _size;
    int _abc;
};
//class Time
//{
//  public:
//     Time(int hour = 0)
//        :_hour(222)
//     {
//        cout << "Time()" << endl;
//        cout<<_hour<<endl;         
//     }
//  private:
//      int _hour;
//
//};
//class Date
//{
//  public:
//     Date(int day)
//        {}
//  private:
//      int _day;
//       Time _t;
//
//};
int main()
{
  Array *a;
  cout<<a <<endl;
}
