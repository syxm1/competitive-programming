#include <bits/stdc++.h>
using namespace std;

/*
 * consider we have two pointer--1 in the first and 1 in the second array--that move thoroughly through the array.
 * chose either to skip 1 character of the first or the second array.
 * pick 1 character from both array if it's equal and add it to the lcs. -> greedy choice
 */

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n + 5), b(m + 5);

  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int j = 1; j <= m; j++) cin >> b[j];

  vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        if (dp[i][j - 1] > dp[i - 1][j]) {
          dp[i][j] = dp[i][j - 1];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
  }

  vector<int> ans;

  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (a[i] == b[j]) {
      ans.push_back(a[i]);
      i--, j--;
    } else {
      if (dp[i][j - 1] > dp[i - 1][j]) {
        j--;
      } else {
        i--;
      }
    }
  }

  cout << dp[n][m] << '\n';
  for (int i = (int) ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " \n"[i == 0];
  }
}
