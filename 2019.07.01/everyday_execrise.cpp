#include <iostream>
#include <vector>
using namespace std;

int num_root(int num)
{
  if (num < 10)
  {
    return num;

  }
  return num_root(num / 10) + num % 10;

}

int main()
{
  int num1;
  int ret;
  while (cin >> num1)
  {
    ret = num_root(num1);
    while(ret >= 10)
    {
      ret = num_root(ret);

    }
    cout<<ret<<" ";

  }
  return 0;

}
