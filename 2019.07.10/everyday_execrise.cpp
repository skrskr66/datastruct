//输出斐波那契数列，如果超过6位，则输出最后六位
//1~100000

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  long long f[100001] = { 1, 1  };
  int n;
  for (int i = 1; i < 100000; i++)
  {
    f[i + 1] = (f[i] + f[i - 1]) % 1000000;
  }
  while (cin >> n)
  {
    if (n < 29)
    {
      cout << f[n] << endl;
    }
    else
    {
      printf("%06d\n", f[n]);
    }
  }
  return 0;
}
