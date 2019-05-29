#include <iostream>
#include <vector>

using namespace std;

int main(){
  int m, n;
  while (cin >> m >> n) {
  vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 1;
        continue;
      }
      if (i == 0) {    // 上边界
        dp[i][j] = dp[i][j - 1];
      } else if (j == 0) {    // 左边界
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }
  cout << dp[n][m] << endl;
  }
return 0;
}
