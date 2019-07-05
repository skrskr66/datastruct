//居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。
//nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。
//只知道假币的重量比真币的质量要
//给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。
#include <iostream>

using namespace std;

int main()
{
  int num;
  while(cin>>num)
  {
    if(num == 0)
    {
      break;
    }
    if(num == 1)
    {
      cout<<0<<endl;
    }
    else if(num == 3 || num == 2)
    {
      cout<<1<<endl;
    }
    else
    {
      int count = 1;
      while(num > 3)
      {
        if(num %3 == 0)
        {
          num /= 3;
          count++;
        }
        else
        {
          num = (num/3) + 1;
          count++;
        }
      }
      cout<<count<<endl;
    }
  }
  return 0;
}

