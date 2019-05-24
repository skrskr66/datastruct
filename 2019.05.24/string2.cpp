#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
  int num, max = 0, tmp1 = 0, tmp2 = -1;
  cin >> num;
  int arr[num];
  for (int i = 0; i < num; i++)
  {
    cin >> arr[i];
    tmp1 += arr[i];
    if (tmp1 > max)
    {
      max = tmp1;

    }
    if (tmp1 < 0)
    {
      tmp1 = 0;
    }
  }
  cout << max << endl;
  return 0;
}
