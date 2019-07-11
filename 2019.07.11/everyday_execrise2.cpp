//NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；
//并且，所有人在这家店吃了两天早餐后，接下来每天都会带一位新朋友一起来品尝。
//于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……
//现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。
#include <iostream>

using namespace std;

int main()
{
  long long num1,num2;
  long long f[81] = {1,1};
  while(cin>>num1>>num2)
  {
    for(int i = 1;i < 80;i++)
    {
      f[i + 1] = f[i - 1] + f[i];
    }
    long long sum = 0;
    for(int i = num1 - 1;i < num2;i++)
    {
      sum += f[i];
    }
    cout<<sum<<endl;
  }
  return 0;
}
