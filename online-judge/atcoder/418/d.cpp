#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string t;
  cin >> t;

  vector<vector<int>> dp(n, vector<int>(2, 0));

  dp[0][t[0] - '0'] = 1;

  int ans = dp[0][1];
  for (int i = 1; i < n; i++) {
    int cur = t[i] - '0';
    dp[i][cur]++;
    if (cur == 0) dp[i][0] += dp[i-1][1], dp[i][1] += dp[i-1][0];
    if (cur == 1) dp[i][0] += dp[i-1][0], dp[i][1] += dp[i-1][1];
    trace(i);
    trace(dp[i][0]);
    trace(dp[i][1]);
    ans += dp[i][1];
  }

  cout << ans << '\n';
}
