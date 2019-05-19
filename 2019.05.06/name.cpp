#include <iostream>

namespace skr{
  int a = 10;
  int add(int b, int c){
    return b + c;
  }
}

using namespace skr;

int main(){
  std::cout<< skr::a << std::endl;
  std::cout<<"hello world!"<< std::endl;
  add(10,20); 
  return 0;
}
