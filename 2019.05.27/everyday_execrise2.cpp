#include <iostream>

using namespace std;

int main()
{
  int n;
  int a = 0,b = 1, c=1;
  int arr[31]={0,1,1};
  int tmp1=0,tmp2=0;
  while(cin>>n && 1<=n<=1000000)
  {
    for(int i = 3;i < 31;i++)
    {
      a = b;
      b = c;
      c = a+ b;
      arr[i] = c;

    }

    for(int j = 0;j < 31;j++)
    {
      if(n == arr[j])
      {
        cout<<0;
        break;
      }
      if(n > arr[j - 1] && n < arr[j])
      {
        tmp1 = n-arr[j-1];
        tmp2 = n-arr[j]*(-1);
        if(tmp1 - tmp2 > 0)
        {
          cout<<tmp2;
          break;
        }
        else
        {
          cout<<tmp1;
          break;
        }
      }
    }
  }
  return 0;
}
