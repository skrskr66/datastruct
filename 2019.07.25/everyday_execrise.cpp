//现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1,1),B在(n,m)。现在A想要拜访B，由于她只想去B的家，所以每次她只会走(i,j+1)或(i+1,j)这样的路线，在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格),问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？
//输入描述:
//第一行N，M，K(1 ≤ N,M ≤ 20, k ≤ 100),N,M为草地大小，接下来K行，每行两个整数x，y，代表(x,y)处有一个蘑菇。
//输出描述:
//输出一行，代表所求概率(保留到2位小数)
//  示例1
//  输入
//  2 2 1
//  2 1
//  输出
//  0.50

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
  int n,m,k;
  while(cin>>n>>m>>k)
  {
    vector<vector<int>> table((n+1),vector<int>(m+1));
    vector<vector<double>> P((n+1),vector<double>(m+1));
    int x,y;
    for(int i = 0;i < k;i++)
    {
      cin>>x>>y;
      table[x][y] = 1;
    }
    P[1][1] = 1.0;
    for(int i = 1;i <= n;i++)
    {
      for(int j = 1;j <= m;j++)
      {
        if(!(i == 1 && j == 1))
        {
          P[i][j] = P[i - 1][j] * (j == m ? 1 : 0.5) + P[i][j - 1] *(i == n ? 1 : 0.5); 

          if(table[i][j] == 1) 
            P[i][j] = 0;
        }
      }
    }
    printf("%.2lf\n",P[n][m]);
  }
}
