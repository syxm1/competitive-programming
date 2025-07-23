#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string x, y;
  cin >> x >> y;

  const int n = x.length();
  const int m = y.length();

  vector<vector<int>> dp(n + 5, vector<int>(m + 5));
  
  // base case
  for (int i = 0; i <= n; i++) dp[i][0] = i;
  for (int i = 0; i <= m; i++) dp[0][i] = i;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cost = (x[i - 1] != y[j - 1]);
      dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + cost});
      // cout << dp[i][j] << ' ';
    }
    // cout << '\n';
  }

  cout << dp[n][m] << '\n';
}
