//所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积即 
//a = a1 × a2 × a3 × ... × an,并且 1 < a1 ≤ a2 ≤ a3 ≤ ...
//≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int num;
  while (cin >> num)
  {
    cout << num << " = ";
    int* num1 = new int[1000];
    int j = 0;
    for (int i = 2; i <= sqrt(num); i++)
    {
      while (num % i == 0)
      {
        if (num != 1)
        {
          num1[j] = i;
          j++;
          num /= i;
        }
      }
    }
    if (num != 1)
    {
      num1[j] = num;
      j++;
    }
    for (int k = 0; k < j; k++)
    {
      cout << num1[k];
      if (k + 1 < j)
      {
        cout << " * ";
      }
    }
    cout << endl;
  }
  return 0;
}
