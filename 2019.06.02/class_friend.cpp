#include <iostream>
using namespace std;
class Date
{
  friend ostream& operator<<(ostream& _cout, const Date& d);
  friend istream& operator>>(istream& _cin, Date& d);
public:
  Date(int year, int month, int day)
    :_year(year)
    ,_month(month)
    ,_day(day)
  {}
private:
  int _year;
  int _month;
  int _day;
};

ostream& operator<<(ostream& _cout,const Date& d)
{
  _cout<<d._year<<"-"<<d._month<<"-"<<d._day;
  return _cout;
}
//这里不能加const，如果加了const就不能对对象d的成员变量进行修改了
istream& operator>>(istream& _cin,Date& d)
{
  _cin>>d._year;
  _cin>>d._month;
  _cin>>d._day;
  return _cin;
}

int main()
{
  Date d(2017,12,24);
  cin>>d;
  cout<<d<<endl;
  return 0;
}
