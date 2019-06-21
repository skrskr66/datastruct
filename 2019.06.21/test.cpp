#include<iostream>

using namespace std;

int main()
{
  int n = 1;
  int sum = 1;
  while(n != 10001)
  {
    sum = sum * n; 
    n++;
  }
  cout<<sum<<endl;
  return 0;
}
