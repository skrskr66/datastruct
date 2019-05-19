#include <iostream>
class Time
{
  public:
    Time()
    {
      std::cout << "Time()" << std::endl;
      // 比特科技
      //   8. 成员变量的命名风格
      _hour = 0;
      _minute = 0;
      _second = 0;
    }
  private:
    int _hour;
    int _minute;
    int _second;
};
class Date
{
  private:
    // 基本类型(内置类型)
    int _year;
    int _month;
    int _day;
    // 自定义类型
    Time _t;
};
int main()
{
  Date d;
  return 0;
}
