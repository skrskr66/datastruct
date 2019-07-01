//数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；
//如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
//比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
//再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
//现在给你一个正整数，输出它的数根。
#include <iostream>
#include <vector>
#include <string>
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
  string num1;
  int ret;
  while (cin >> num1)
  {
    int sum = 0;
    for(auto t = num1.begin();t != num1.end();t++)
    {
      sum += (*t) - '0';
    }
    ret = num_root(sum);
    while (ret >= 10)
    {
      ret = num_root(ret);
    }
    cout << ret <<" ";
  }
  return 0;
}
