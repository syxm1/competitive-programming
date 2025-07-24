#include <bits/stdc++.h>
using namespace std;
 
#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif
 
#define int int64_t
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, m;
  cin >> n >> m;
 
  vector<tuple<int, int, int>> edges;
 
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(make_tuple(--u, --v, w));
  }
 
  vector<int> distance(n, 1e15), prev(n);
  int end_cycle = -1;
 
  distance[0] = 0;
 
  for (int i = 0; i < n; i++) {
    for (auto [u, v, w] : edges) {
      if (distance[v] > distance[u] + w) {
        distance[v] = distance[u] + w;
        prev[v] = u;
        if (i == n - 1) end_cycle = v;
      }
    }
  }
 
  if (end_cycle == -1) {
    cout << "NO\n";
    return 0;
  }
 
  vector<int> cycle;
  vector<bool> vis(n, 0);
  int cur_node = end_cycle;

  while (1) {
    cycle.push_back(cur_node);
    if (vis[cur_node]) break;
    vis[cur_node] = 1;
    cur_node = prev[cur_node];
  }
  
  reverse(cycle.begin(), cycle.end());
 
  cout << "YES\n";
  for (int i = 0; i < (int) cycle.size(); i++) {
    cout << cycle[i] + 1 << " \n"[i == n-1];
    if (i > 0 && cycle[i] == cycle[0]) break;
  }
}
