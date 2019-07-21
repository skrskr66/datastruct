//马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因，
//要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。
//输入描述:
//首先一个正整数N，表示人员个数。 
//之后N行，每行三个数，分别对应马戏团员编号，体重和身高。
//输出描述:
//正整数m，表示罗汉塔的高度。
//示例1
//输入
//6
//1 65 100
//2 75 80
//3 80 100
//4 60 95
//5 82 101
//6 81 70
//输出
//4

#include <iostream>
#include <vector>

using namespace std;

struct Actor
{
  int height;
  int weight;
  Actor(int h,int w):height(h),weight(w)
  {}
};



int main()
{
  return 0;
}
