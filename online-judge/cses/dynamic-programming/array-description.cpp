#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mod = 1e9+7;
const int mxn = 1e5+5;
const int mxm = 1e2+5;

int n, m, arr[mxn], dp[mxn][mxm];

bool valid(int a, int b) {
  return abs(a - b) <= 1;
}

int solve(int id, int prev) {
  if (id == n) {
    return 1;
  }

  if (dp[id][prev] != -1) {
    return dp[id][prev];
  }

  if (arr[id] == 0) {
    int ret = solve(id + 1, prev);
    if (prev + 1 <= m) ret = (ret + solve(id + 1, prev + 1)) % mod;
    if (prev - 1 >= 1) ret = (ret + solve(id + 1, prev - 1)) % mod;
    return dp[id][prev] = ret;
  } 

  return dp[id][prev] = (valid(prev, arr[id]) ? solve(id + 1, arr[id]) : 0);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < mxn; i++) {
    for (int j = 0; j < mxm; j++) {
      dp[i][j] = -1;
    }
  }

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (arr[0] == 0) {
    int ans = 0;

    for (int i = 1; i <= m; i++) {
      ans = (ans + solve(1, i)) % mod;
    }

    cout << ans << '\n';

    return 0;
  }

  cout << solve(1, arr[0]) << '\n';
}
