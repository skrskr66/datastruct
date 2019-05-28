#include <iostream>
//求最小公倍数
//最小公倍数 * 最大公约数 = 两数相乘

using namespace std;

int main()
{
  int a, b, tmp = 0;
  cin >> a;
  cin >> b;
  int sum = a * b;
  if (a<b)
  {
    tmp = a;
    a = b;
    b = tmp;

  }
  while (b != 0)
  {
    tmp = a % b;
    a = b;
    b = tmp;

  }
  int tmp2 = 0;
  tmp2 = sum/ a;
  cout << tmp2;
  return 0;

}

