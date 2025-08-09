#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

const int mod = 1e9+7;
const int mxn = 2e5+5;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> fac(mxn, 1);
  for (int i = 2; i < mxn; i++) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= mod;
  }

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    if (m >= n) {
      cout << 0 << '\n';
      continue;
    }

    function<void(int, int, vector<int>&, vector<int>&)> dfs = 
      [&](int cur, int pre, vector<int> &dist, vector<int> &prev) {
      for (int nxt : adj[cur]) {
        if (nxt == pre) continue;
        dist[nxt] = dist[cur] + 1;
        prev[nxt] = cur;
        dfs(nxt, cur, dist, prev);
      }
    };

    vector<int> dist(n, -1), prev(n, -1);
    int head, tail;

    dist[0] = 0;
    dfs(0, -1, dist, prev);
    head = max_element(dist.begin(), dist.end()) - dist.begin();
    dist[head] = 0;
    dfs(head, -1, dist, prev);
    tail = max_element(dist.begin(), dist.end()) - dist.begin();
    
    int curr = tail;
    vector<int> diameter;
    vector<bool> is_diameter(n, 0);

    while (1) {
      diameter.push_back(curr);
      is_diameter[curr] = 1;
      if (curr == head) break;
      curr = prev[curr];
    }

    int ans = 1, ok = 1;

    for (int i = 1; i < (int) diameter.size() - 1; i++) {
      stack<tuple<int, int, int>> s;

      s.push({diameter[i], -1, 0});  
      while (!s.empty()) {
        auto [cur, pre, dis] = s.top();
        s.pop();
        for (int nxt : adj[cur]) {
          if (nxt == pre || is_diameter[nxt]) continue;
          int nxt_dis = dis + 1;
          if (nxt_dis >= 2) ok = 0;
          else s.push({nxt, cur, nxt_dis});
        }
      }

      int num = adj[diameter[i]].size() - 2;
      if (i == 1) num++;
      if (i == (int) diameter.size() - 2) num++;
      if (num == 0) continue;
      ans *= fac[num];
      ans %= mod;
    }

    if (!ok) {
      cout << 0 << '\n';
      continue;
    }

    if (diameter.size() < 4) ans = (ans * 2) % mod;
    else ans = (ans * 4) % mod;

    cout << ans << '\n';
  }
}
