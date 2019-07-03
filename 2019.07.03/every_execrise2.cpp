#include <iostream>
using namespace std;
#include<string.h>

void ad(string s1,string s2){
  int l1=s1.length(),l2=s2.length(); 

  int x[l1+10],y[l2+10];
  memset(x,0,sizeof(x));
  memset(y,0,sizeof(y));

  int i,j,k=0;
  //把s1转换成int数组 
  for(i=l1-1;i>=0;i--){
    x[k++]=s1[i]-'0'; 
  }
  k=0;
  //把s2转换成int数组 
  for(j=l2-1;j>=0;j--){
    y[k++]=s2[j]-'0';
  }
  //逐位累加 
  for(i=0;i<l2+10;i++){
    x[i]+=y[i];
    if(x[i]>=10){
      x[i]-=10;
      x[i+1]+=1;
    }
  }
  //输出计算结果 
  for(i=0;i<l1+10;i++){
    cout<<x[i];
  }
}
int main()
{
  string s1("1");
  string s2("999999999999");
  ad(s1,s2);
  return 0;
}
