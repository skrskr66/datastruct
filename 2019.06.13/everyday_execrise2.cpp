//小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为 a.
//在接下来的一段时间内,他将会依次遇见n个怪物,每个怪物的防御力为b1,b2,b3...bn. 
//如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,并 且使得自己的能力值增加bi;
//如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi 与c的最大公约数.
//那么问题来了,在一系列的锻炼后,小易的最终能力值为多少?
#include <iostream>
#include <vector>
using namespace std;

int get_num(int num1,int num2)
{
  while(num2)
  {
    int tmp = num2;
    num2 = num1 % num2;
    num1 = tmp;
  }
  return num1;
}

int main()
{
  size_t num = 0,val = 0;
  while(cin>>num>>val)
  {
    vector<size_t> v(num,0);
    for(size_t i = 0;i<num;i++)
    {
      cin>>v[i];
    }
    for(size_t j = 0;j < num;j++)
    {
      if(val >= v[j])
      {
        val += v[j];
      }
      else
      {
        int temp = get_num(val,v[j]);
        val +=temp;
      }
    }
    cout<<val<<endl;
  }
  return 0;
}
