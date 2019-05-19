#include <iostream>
using std::cout;
using std::endl;
int add(int a,int b){
  return a + b;
}

double add(double a, double b){
  return a + b;
}

long add(long a,long b){
  return a - b;
}

int main(){
  cout<<add(10,20)<<endl;
  cout<<add(10.1,20.0)<<endl;
  cout<<add(10L,20L)<<endl;
  return 0;
}
