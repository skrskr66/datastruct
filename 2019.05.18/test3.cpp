#include <iostream>
class Date
{
  public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
      _year = year;
      _month = month;
      _day = day;
    }
    void Print(){
      std::cout<<_year<<"-"<<_month<<"-"<<_day<<std::endl;
    }
  private:
    int _year;
    int _month;
    int _day;
};
int main()
{
  Date d1;
  // 这里d2调用的默认拷贝构造完成拷贝，d2和d1的值也是一样的。
  Date d2(d1);
  d2.Print();
  return 0;
}
