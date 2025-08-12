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

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    if (n <= 3) {
      cout << 0 << '\n';
      continue;
    }

    int leaf = 0;
    for (int i = 0; i < n; i++) {
      if (adj[i].size() == 1) leaf++;
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      int cur = leaf;
      for (int j : adj[i]) {
        if (adj[j].size() == 1) cur--;
      }
      ans = min(ans, cur);
    }

    cout << ans << '\n';
  }
}
