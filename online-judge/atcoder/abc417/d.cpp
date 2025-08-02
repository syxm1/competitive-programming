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

  vector<tuple<int, int, int>> v(n + 5);
  vector<int> pref(n + 5, 0);

  for (int i = 1; i <= n; i++) {
    int p, a, b;
    cin >> p >> a >> b;
    v[i] = make_tuple(p, a, b);
    pref[i] = pref[i - 1] + b;
  }

  vector<vector<int>> dp(n + 5, vector<int>(1e3 + 5));

  for (int i = 0; i <= 1e3; i++) {
    dp[n+1][i] = i;
  }

  for (int i = n; i > 0; i--) {
    auto [p, a, b] = v[i];
    for (int j = 0; j <= 1e3; j++) {
      if (j <= p) dp[i][j] = dp[i+1][j+a];
      else dp[i][j] = dp[i+1][max(0ll, j-b)];
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int x;
    cin >> x;

    int lo = 0, hi = n, id = n;

    while (lo <= hi) {
      int md = (lo + hi) >> 1;
      if (x - pref[md] <= 500) {
        id = md;
        hi = md - 1;
      } else {
        lo = md + 1;
      }
    }

    trace("ok");
    trace(id);

    if (id == n) {
      cout << x - pref[n] << '\n';
      continue;
    }

    x = max(0ll, x - pref[id]);
    x = dp[id + 1][x];

    cout << x << '\n';
  }
}
