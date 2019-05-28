#include <iostream>

using namespace std;

int main()
{
  int W,H;
  int arr[1000][1000] = {0};
  int count = 0;
  while(cin>>W>>H && 1<=W<=1000 && 1<=H<=1000)
  {
    for(int i = 0;i < W; i++)
    {
      for(int j = 0;j < H;j++)
      {
        if(arr[i][j] == 0)
        {
          count++;
          if((i+2) < W)
          {
            arr[i+2][j]=1;

          }
          if((j+2) < H)
          {
            arr[i][j+2]=1;

          }

        }

      }

    }
    cout<<count;
    /*
     *         for(int j = 0;j < W;j++)
     *                 {
     *                             printf("%d ",arr[j]);
     *                                     }
     *                                             */
  }
  return 0;
}


