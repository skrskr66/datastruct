
//编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
  int n,m;
  while(cin>>m>>n)
  {
    vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    for(int i = 0;i<n;i++)
    {
      for(int j = 0;j<m;j++)
      {
        if(i == 0 && j == 0)
        {
          dp[i][j] = 1;
          continue;
        }

        if(i == 0)
        {
          dp[i][j] = dp[i][j-1]; //沿着上边界走
        }
        else if(j == 0)
        {
          dp[i][j] = dp[i - 1][j];//沿着右边界走
        }
        else
        {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//如果不是在边界，记录的数为从该位置走到终点的路径数
        }
      }
    }
    cout<<dp[n][m]<<endl;
  }
  return 0;
}
