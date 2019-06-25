#include <iostream>
#include <string>

using  namespace std;
class Person
{
  public:
    void Print()
    {
      cout<<"---"<<endl;
    }
  protected :
    string _name; // 姓名
    string _sex; // 性别
    int _age; // 年龄

};
class Student : public Person
{
  public :
    void Print()
    {
      cout<<"_No"<<_No<<endl;
    }
    int _No ; // 学号

};

void test()
{
  Student A;
  //子类对象可以赋值给父类对象/指针/引用
  Person B;
  Person* bb = &A;
  Person& aa = A;
  bb->Print();
  aa.Print();
  
  //A = B;这是错误的赋值方式，基类的对象不能赋值给派生类对象
  
  //基类的指针可以通过强制类型转换赋值给派生类的指针
  bb = &A;
  Student* pp1 = (Student*)bb;
  pp1->_No = 10;
  pp1->Print();

  bb = &B;
  Student* pp2 = (Student*)bb;//这相当于将基类强转成派生类，在赋值给派生类,这种转换虽然可以，但会是存在越界访问的情况
  pp2->_No = 1000;
  pp2->Print();
}

int main()
{
  test();
  return 0;
}
