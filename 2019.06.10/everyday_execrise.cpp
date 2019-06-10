//在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
//要求：
//实现如下2个通配符：
//*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
//？：匹配1个字符

//输入：
//通配符表达式；
//一组字符串。
//输出：
//返回匹配的结果，正确输出true，错误输出false

#include <iostream>
#include <string>
using namespace std;

bool get_compare(const char* str1,const char* str2)
{    
  if(*str1 == '\0' && *str1 == '\0')
  {
    return true;
  }

  if(*str1 == '\0' || *str2 == '\0')
  {
    return false;
  }

  if(*str1 == '?')
  {
    return get_compare(str1 + 1,str2 + 1);
  }
  else if(*str1 == '*')
  {
    return get_compare(str1+1,str2) || get_compare(str1 + 1,str2 + 1) || get_compare(str1,str2+1);
  }
  else if(*str1 == *str2)
  {
    return get_compare(str1 + 1,str2 + 1);
  }
  return false;
}

int main()
{
  string str1,str2;
  while(cin>>str1>>str2)
  {
    bool ret = get_compare(str1.c_str(),str2.c_str());
    if(ret)
    {
      cout<<"true"<<endl;
    }
    else
    {
      cout<<"false"<<endl;
    }
  }
  return 0;
}
