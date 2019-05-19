#include<iostream>
using std::cout;
using std::endl;

int TestAuto(){
  return 10;
}

int main(){
  int a = 10;
  auto b = a;
  auto* c = &a;
  auto& d = a;

  cout<<"b is"<< b <<endl;
  cout<< a <<endl;
  cout<< c <<endl;
  cout<< d <<endl;

}
