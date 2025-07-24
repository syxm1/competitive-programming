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

  vector<vector<pair<int, int>>> adj(n);

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[--u].push_back(make_pair(--v, w));
  }

  vector<int> distance(n, 1e18), routes(n, 0), min_flight(n, 1e18), max_flight(n, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  distance[0] = 0;
  routes[0] = 1;
  min_flight[0] = 0;
  pq.push(make_pair(0, 0));

  while (!pq.empty()) {
    auto [cur_distance, cur_node] = pq.top();
    pq.pop();

    for (auto [nxt_node, weight] : adj[cur_node]) {
      if (distance[nxt_node] > cur_distance + weight) {
        distance[nxt_node] = cur_distance + weight;
        routes[nxt_node] = routes[cur_node];
        min_flight[nxt_node] = min_flight[cur_node] + 1;
        max_flight[nxt_node] = max_flight[cur_node] + 1;
        pq.push(make_pair(distance[nxt_node], nxt_node));
      } else if (distance[nxt_node] == cur_distance + weight) {
        routes[nxt_node] += routes[cur_node];
        routes[nxt_node] %= mod;
        min_flight[nxt_node] = min(min_flight[nxt_node], min_flight[cur_node] + 1);
        max_flight[nxt_node] = max(max_flight[nxt_node], max_flight[cur_node] + 1);
      }
    }
  }

  cout << distance[n - 1] << ' ' << routes[n - 1] << ' ' << min_flight[n - 1] << ' ' << max_flight[n - 1] << '\n';
}
