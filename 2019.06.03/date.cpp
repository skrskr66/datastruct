#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
  public:
    inline int Getmonthday(int year,int month)const
    {
      static int monthArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
      if((month == 2) && (((year % 4 == 0)&&(year % 100 == 0))||(year % 400 == 0)))
      {
        return 29; 
      }
      return monthArray[month];
    }
    Date(int year = 1900,int month = 1,int day = 1)
    {
      if(year>=1900 && month >0&& month <13 && day>0 && day < Getmonthday(year,month))
      {
        _year = year;
        _month = month;
        _day = day;
      }
      else
      {
        cout<<"非法日期"<<endl;
      }
    }

    void print()
    {
      cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
    }
    bool operator>(const Date& d) const
    {
      if(_year > d._year)
      {
        return true;
      }
      else if(_year == d._year)
      {
        if(_month > d._month)
        {
          return true;
        }
        else if (_month == d._month)
        {
          if(_day > d._day)
          {
            return true;
          }
        }
      }
      return false;
    }
    bool operator>=(const Date& d) const
     {
      if(_year >= d._year)
      {
        return true;
      }
      else if(_year == d._year)
      {
        if(_month >= d._month)
        {
          return true;
        }
        else if (_month == d._month)
        {
          if(_day >= d._day)
          {
            return true;
          }
        }
      }
      return false;
    }
   bool operator<(const Date& d) const
   {
     return !(*this > d);
   }
    bool operator<=(const Date& d) const
    {
      return !(*this >= d);
    }
    bool operator==(const Date& d) const
    {
      return _year == d._year && _month == d._month && _day == d._day;
    }
    bool operator!=(const Date& d) const
    {
      return !(*this == d);
    }
    Date& operator++()
    {
      *this += 1; 
      return *this;
    }// 前置++
    Date operator++(int)
    {
      Date ret(*this);
      *this += 1;
      return ret;
    }// 后置++

    Date& operator--()
    {
      *this -= 1;
      return *this;
    }// 前置--
    Date operator--(int)//后置不是引用，结束后变量释放了，所以先拷贝到另一个变量中，在进行加减操作，最后返回该变量
    {
      Date ret(*this);
      *this -= 1;
      return ret;
    }// 后置--

    Date operator+(int day) const
    {
      Date ret = (*this);
      ret += day;
      return ret;
    }
    Date operator-(int day) const{
      Date ret = (*this);
      ret -= day;
      return ret;
    }

    Date& operator+=(int day)
    {
      if(day < 0)
      {
        return *this -= -day;
      }
      _day += day;
      while(_day > Getmonthday(_year,_month))
      {
        _day -= Getmonthday(_year,_month);
        _month++;
        if(_month == 13)
        {
          ++_year;
          _month = 1;
        }
      }
      return *this;
    }
    Date& operator-=(int day)
    {
      if(day < 0)
      {
        return *this += -day;
      }
      _day -= day;
      while(_day < 0)
      {
        --_month;
        if(_month == 0)
        {
          _month = 12;
          --_year;
        }
        _day += Getmonthday(_year,_month);
      }
      return *this;
    }
    int operator-(const Date& d)const
    {
       Date maxdate(*this);
       Date mindate(d);
       int flag = 1;
       if(*this < d)
       {
         maxdate = d;
         mindate = *this;
         flag = -1;
       }
       int days = 0;
       while(maxdate != mindate)
       {
         mindate += 1;
         ++days;
       }
       return days * flag;
    }
    ~Date()
    {

    }

  private:
    int _year;
    int _month;
    int _day;
};
int main()
{
  Date d(2019,6,3);
  d.print();
  d += 12;
  d.print();
  d -= 13;
  d.print();
  d++;
  d.print();
  ++d;
  d.print();
  Date d1;
  d1 = d-40;
  d1.print();
  Date d2(2018,3,12);
  d2.print();
  if(d2<d1)
  {
   cout<< "d2小"<<endl;
  }
  else
  {
    cout<<"d1小"<<endl;
  }
  return 0;
}
