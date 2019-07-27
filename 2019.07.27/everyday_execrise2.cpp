//广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，请你帮忙找出身高依次递增的子序列。
//例如队伍的身高数据是（1、7、3、5、9、4、8）
//其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。
//
//输入描述:
//输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000）。
//
//紧接着第二行包含n个正整数m（1≤n≤10000），代表队伍中每位队员的身高。
//
//
//输出描述:
//对应每一组数据，输出最长递增子序列的长度。
//示例1
//输入
//7
//1 7 3 5 9 4 8
//6
//1 3 5 2 4 6
//输出
//4
//4

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int m;
  while(cin>>m)
  {
    vector<int> dp(m,0);
    for(int i = 0;i < m;i++)
    {
      cin>>dp[i];

    }
    vector<int> f(m+1,1);
    int ret = 1;
    for(int i = 1;i < m;i++)
    {
      for(int j = 0;j < i;j++)
      {
        if(dp[i] > dp[j])
        {
          f[i] = max(f[i],f[j] + 1);

        }

      }
      ret = max(ret,f[i]);

    }
    cout<<ret<<endl;

  }
  return 0;

}
