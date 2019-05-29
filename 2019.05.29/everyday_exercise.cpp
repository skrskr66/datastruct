#include <iostream>

using namespace std;
int addAB(int A, int B) {
  // write code here
  //         //return A+B;//???
  int sum,tmp;
  while(B != 0)
  {
    sum = A ^ B;
    tmp = (A & B) << 1;
    A = sum;
    B = tmp;
  }
  return A;
}

int main()
{
  addAB(2,3);
  cout<<addAB(2,3)<<endl;
  return 0;
}
