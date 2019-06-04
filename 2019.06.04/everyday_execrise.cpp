//润年条件记错，找了快两个小时的BUG
#include <iostream>

using namespace std;

class Date
{
  public:
    inline int GetMonthDay(int year, int month) const
    {
      static int MonthArray[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31  };
      if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
      {
        return 29;

      }
      return MonthArray[month - 1];

    }
    Date(int year, int month, int day)
    {
      if (year>1 && month > 0 && month <13 && day > 0 && day <= GetMonthDay(year, month))
      {
        _year = year;
        _month = month;
        _day = day;

      }
      else
      {
        cout << -1 << endl;

      }

    }
    void print()
    {
      cout << _year << endl;
      cout << _month << endl;
      cout << _day << endl;

    }
    Date& operator+=(int day)
    {
      if (day < 0)
      {
        return *this -= -day;

      }
      _day += day;
      if (_day > GetMonthDay(_year, _month))
      {
        _day -= GetMonthDay(_year, _month);
        _month++;
        if (_month == 13)
        {
          _year++;
          _month = 1;

        }

      }
      return *this;

    }
    Date& operator-=(int day)
    {
      if (day < 0)
      {
        return *this += -day;

      }
      _day -= day;
      while (_day < 0)
      {
        _month--;
        if (_month == 0)
        {
          --_year;
          _month = 12;

        }
        _day += GetMonthDay(_year, _month - 1);

      }
      return *this;

    }
    int operator-(const Date&d)const
    {
      Date mindate(d);
      Date maxdate(*this);
      int flag = 1;
      if (d > *this)
      {
        mindate = *this;
        maxdate = d;

      }
      int days = 0;
      while (mindate != maxdate)
      {
        mindate += 1;
        ++days;

      }
      ++days;
      return days;

    }
    bool operator>(const Date& d) const
    {
      if (_year > d._year)
      {
        return true;

      }
      else if (_year == d._year)
      {
        if (_month > d._month)
        {
          return true;

        }
        else if (_month == d._month)
        {
          if (_day > d._day)
          {
            return true;

          }

        }

      }

      return false;

    }

    bool operator>=(const Date& d) const
    {
      return *this > d || *this == d;

    }

    bool operator<(const Date& d) const
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
  private:
    int _year;
    int _month;
    int _day;

};

int main()

{
  int year, month, day;
  while (cin >> year >> month >> day)
  {
    Date d(year, month, day);
    Date d1(year, 1, 1);
    int ret = (d1 - d);
    cout<<ret<<endl;

  }
  return 0;

}
