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

  int t;
  cin >> t;

  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    --x, --y;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
      sort(adj[i].rbegin(), adj[i].rend());
    }

    vector<int> prev(n, 1e9);
    stack<pair<int, int>> dfs;

    dfs.push({x, -1});

    while (!dfs.empty()) {
      auto [cur, pre] = dfs.top();
      dfs.pop();

      prev[cur] = pre;

      if (cur == y) {
        break;
      }

      for (int nxt : adj[cur]) {
        if (prev[nxt] != 1e9) continue;
        dfs.push({nxt, cur});
      }
    }

    vector<int> ans;
    int c = y;

    while (1) {
      ans.push_back(c);
      if (c == x) break;
      c = prev[c];
    }

    reverse(ans.begin(), ans.end());

    for (int i : ans) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}
