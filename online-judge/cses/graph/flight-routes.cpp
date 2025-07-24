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

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pair<int, int>>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[--u].push_back({--v, w});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  vector<priority_queue<int>> distance(n);

  pq.push(make_pair(0, 0));
  distance[0].push(0);

  while (!pq.empty()) {
    auto [cur_distance, cur_node] = pq.top();
    pq.pop();

    if (cur_distance > distance[cur_node].top()) continue;

    for (auto [nxt_node, weight] : adj[cur_node]) {
      int new_distance = cur_distance + weight;
      if ((int) distance[nxt_node].size() < k || new_distance < distance[nxt_node].top()) {
        distance[nxt_node].push(new_distance);
        if ((int) distance[nxt_node].size() > k) distance[nxt_node].pop();
        pq.push(make_pair(new_distance, nxt_node));
      }
    }
  }

  vector<int> ans;
  while (!distance[n - 1].empty()) {
    ans.push_back(distance[n - 1].top());
    distance[n - 1].pop();
  }
  reverse(ans.begin(), ans.end());

  for (int i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
