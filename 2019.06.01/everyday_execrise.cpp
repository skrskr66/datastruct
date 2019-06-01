#include <iostream>

using namespace std;

bool prime(int n)
{
  if(n == 1 || n==2)
  {
    return true;
  }
  else
  {
    for(int i = 3;i<n;i++)
    {
      if(n % i == 0)
      {
        return false;
      }
    }
    return true;
  }
}

int main()
{
  int n;
  while(cin>>n && (n%2==0))
  {
    int a = 0,b = 0;
    for(int i = 0;i<=n/2;i++)
    {
      if(prime(i) && prime(n-i))
      {
        if(i > a)
        {
          a = i;
          b = n - i;
        }
      }
    }
    cout<<a<<endl;
    cout<<b<<endl;
  }
  return 0;
}
