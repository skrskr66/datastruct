#include <stdio.h>

int fab(int i)
{
  if(i == 0)
  {
    return 0;
  }
  if(i == 1)
  {
    return 1;
  }
  else
  {
  return fab(i-1) + fab(i-2);
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  printf("%d",fab(n));
  return 0;
}
