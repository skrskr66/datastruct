//输入描述:
//先输入字典中单词的个数n，再输入n个单词作为字典单词。
//再输入一个单词，查找其在字典中兄弟单词的个数m
//再输入数字k
//
//输出描述:
//根据输入，输出查找到的兄弟单词的个数m
//然后输出查找到的兄弟单词的第k个单词。
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isBrother(string str, string s){   
  if(str.size() == s.size()){
    if(str == s)
      return false;
    sort(str.begin(), str.end());
    sort(s.begin(), s.end());
    if(str == s)
      return true;
  }
  return false;
}
int main(){
  int num;
  while(cin >> num){
    string str;
    string word,s;
    int index;
    vector<string> vs;
    for(int i = 0; i < num; ++i){
      cin >> str;
      vs.push_back(str);
    } 
    sort(vs.begin(), vs.end());  // 因为是字典，一定要排序！！
    cin >> word;
    cin >> index;
    int counts = 0;
    for(int i = 0; i < num; ++i){
      if(isBrother(word, vs[i])){
        counts ++;
        if(counts == index)
          s = vs[i];
      }
    }
    if(!vs.empty())
      cout << counts << endl;
    if(counts >= index)
      cout << s << endl; 
  }
  return 0;
}
