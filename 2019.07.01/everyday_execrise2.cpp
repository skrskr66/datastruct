#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
typedef  long long LL;
const LL maxn = 1e4+5;

int n, num[maxn], fib[maxn];
void init()
{ //初始化斐波那契数列
  fib[1] = 1, fib[2] = 2;
  for(int i = 3; i <= maxn; i++)
    fib[i] = (fib[i-1]%10000+fib[i-2]%10000)%10000;
}
void solve()
{
  for(int i = 1; i <= n; i++)
    printf("%04d",fib[num[i]]);
  printf("\n");
}
int main()
{
  init();
  while(cin >> n){
    for(int i = 1; i <= n; i++)
      cin >> num[i];
    solve();
  }
  return 0;
}

