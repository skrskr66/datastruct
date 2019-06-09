//有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？
//本质上就是斐波那契数列
#include <iostream>
using namespace std;

int get_num(int m)
{
  if(m == 1||m == 2)
  {
    return 1;
  }
  return get_num(m - 1)+get_num(m - 2);
}

int main()
{
  int m;
  while(cin>>m)
  {
    int ret = get_num(m);
    cout<< ret <<endl;
    ret = 0;
  }
  return 0;
}
