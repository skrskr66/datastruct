#include <iostream>
#include <stdio.h>
void TestRef(){
  int a = 10;
  int b;
  int& ra = a;
  const int& rb = 101000;
  double d = 12.24;
  const double& rd = d;
  printf("%d\n",a);
  printf("%d\n",rb);
  printf("%f\n",rd);
}

int main(){
  TestRef(); 
  return 0;
}
