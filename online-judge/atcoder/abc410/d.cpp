#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int n, m;
vector<vector<bool>> reachable;
vector<vector<pair<int, int>>> adj;

void dfs(int cur_node, int cur_val) {
  for (auto [nxt_node, wei] : adj[cur_node]) {
    int nxt_val = (cur_val ^ wei);

    if (!reachable[nxt_node][nxt_val]) {
      reachable[nxt_node][nxt_val] = 1;      
      dfs(nxt_node, nxt_val);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  adj.resize(n);
  reachable.assign(n, vector<bool>((1 << 10), 0));

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[--u].push_back(make_pair(--v, w));
  }

  dfs(0, 0);

  for (int j = 0; j < (1 << 10); j++) {
    if (reachable[n - 1][j]) {
      cout << j << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
}
