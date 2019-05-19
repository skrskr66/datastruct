#include <iostream>

class A1
{
public:
  void f1(){

  }
private:
  int _a;
};

class A2
{
  public:
    void f2(){}
};

class A3
{};


int main(){
  std::cout<<sizeof(A1)<<sizeof(A2)<<sizeof(A3)<<std::endl;
  return 0;
}
