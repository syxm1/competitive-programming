#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<bool>> reachable;
vector<vector<pair<int, int>>> adj;

void dfs(int cur_node, int cur_score) {
  if (cur_node == n - 1 && reachable[cur_node][cur_score]) 
    return;
  
  reachable[cur_node][cur_score] = 1;
  
  for (auto [nxt_node, weight] : adj[cur_node]) {
    int nxt_score = (cur_score ^ weight);
    if (!reachable[nxt_node][nxt_score]) 
      dfs(nxt_node, nxt_score);
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
    --u, --v;
    adj[u].push_back(make_pair(v, w));
  }
  
  reachable[0][0] = 1;
  dfs(0, 0);

  for (int j = 0; j < (1 << 10); j++) {
    if (reachable[n - 1][j]) {
      cout << j << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
}
