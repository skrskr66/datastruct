#include<iostream>

using namespace std;

//int main()
//{
//  int n,m,count =0;
//  cin>>n;
//  while(n != 0)
//  {
//    m = n % 3;
//    n /= 3;
//    count += n;
//    n = n + m;
//  }
//  return 0;
//}

int main()
{
  string str("hello");
  int pos = str.find(str[2]);
  cout<<pos<<endl;
  return 0;
}
