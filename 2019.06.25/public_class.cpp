#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
  void Print()
  {
    cout<<"name"<<_name<<endl;
    cout<<"age"<<_age<<endl;
  }
protected:
  string _name = "peter";
  int _age = 18;
};

class Student :public Person
{
protected:
  int _stuid;
};

class Teacher: public Person 
{
protected:
  int _jobid;
};

int main()
{
  Student s;
  Teacher t;
  s.Print();
  t.Print();
}
