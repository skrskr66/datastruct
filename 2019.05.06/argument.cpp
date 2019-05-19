#include <iostream>

using std::cout;
using std::endl;

void Func(int a = 9){
  cout<<a<<endl;
}

void testfunc(int a = 10,int b = 20,int c = 30){
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b<<endl;
  cout<<"c = "<<c<<endl;
}

void testfunc2(int a,int b = 20,int c = 30){
  cout<<"a = "<<a<<endl;
  cout<<"b = "<<b<<endl;
  cout<<"c = "<<c<<endl;
}

int main(){

  //Func();
  //Func(100);
  testfunc();
  testfunc2(10);
  return 0;
}
