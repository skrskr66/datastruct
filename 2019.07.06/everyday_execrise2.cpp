//一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。
//NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int num;
  while (cin >> num)
  {
    int count = 0;
    for (int i = 2; i <= sqrt(num); i++)
    {
      if (num % i == 0)
      {
        count++;
      }
      while (num % i == 0)
      {
        num /= i;
      }
    }
    if (num != 1)
    {
      count++;
    }
    cout << count << endl;
  }
  return 0;
}
