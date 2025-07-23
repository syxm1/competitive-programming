#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mod = 1e9+7;
const int mxn = 1e6+5;

int dp[mxn][2];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  dp[1][0] = 1; // buka
  dp[1][1] = 1; // tutup
  
  for (int i = 2; i < mxn; i++) {
    dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % mod;
    dp[i][1] = (4 * dp[i - 1][1] + dp[i - 1][0]) % mod;
  }

  while (t--) {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % mod << '\n';
  }
}
