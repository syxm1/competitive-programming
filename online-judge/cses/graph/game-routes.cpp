#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int int64_t

const int mod = 1e9+7;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<int> in_degree(n, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[--u].push_back(--v);
    in_degree[v]++;
  }

  queue<int> q;
  vector<int> route(n, 0);

  route[0] = 1;

  for (int i = 0; i < n; i++) {
    if (in_degree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int nxt : adj[cur]) {
      route[nxt] = (route[nxt] + route[cur]) % mod;
      if (--in_degree[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  cout << route[n - 1] << '\n';
}
