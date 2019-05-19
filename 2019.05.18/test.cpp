#include <iostream>


class Date
{ 
  public:
    Date (int year = 1900, int month = 1, int day = 1)
    {
      _year = year;
      _month = month;
      _day = day;

    }
    Date(const Date& d)
    {
      _year = d._year;
      _month = d._month;
      _day = d._day;

    }

  private :
    int _year ;
    int _month ;
    int _day ;
};
// 以下测试函数能通过编译吗？
void Test()
{
  Date d1;
  Date d2(d1);
}

int main(){
  Test();
  return 0;
}
