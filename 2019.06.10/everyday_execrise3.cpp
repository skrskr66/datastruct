//查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
#include <iostream>
#include <string>
using namespace std;
int main() {
  string str1, str2;
  while (cin >> str1 >> str2) {
    string cur;
    if (str2.length() < str1.length()) {
      string str = str1;
      str1 = str2;
      str2 = str;

    }
    for (int i = 1; i <= str1.length(); i++) {
      for (int ii = 0; ii <= str1.length() - i; ii++) {
        string sub = str1.substr(ii, i);
        if (str2.find(sub) != string::npos) {
          cur = sub;
          break;

        }

      }

    }
    cout << cur << endl;

  }
  return 0;

}
