#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mod = 998244353;
const int mxn = 1e5+5;

int n, inv[mxn], one[mxn], zero[mxn];
bool vis[mxn];
vector<vector<pair<int, int>>> adj;

void dfs(int cur) {
  for (int i = adj[cur].size() - 1; i >= 0; i--) {
    auto [nxt, wei] = adj[cur][i];

    if (!vis[nxt]) {
      vis[nxt] = 1;
      dfs(nxt);
    }

    inv[cur] = (inv[cur] + inv[nxt]) % mod;
    inv[cur] = (inv[cur] + (wei == 1) * zero[nxt]) % mod;
    inv[cur] = (inv[cur] + (one[nxt] + (wei == 1)) * zero[cur] % mod) % mod;
    one[cur] = (one[cur] + one[nxt] + (wei == 1)) % mod;
    zero[cur] = (zero[cur] + zero[nxt] + (wei == 0)) % mod;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  adj.resize(n);

  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;

    while (m--) {
      int j, w;
      cin >> j >> w;
      adj[i].push_back(make_pair(--j, w));
    }
  }

  dfs(0);

  /*
  for (int i = 0; i < n; i++) cout << inv[i] << ' '; cout << '\n';
  for (int i = 0; i < n; i++) cout << one[i] << ' '; cout << '\n';
  for (int i = 0; i < n; i++) cout << zero[i] << ' '; cout << '\n';
  */

  cout << inv[0] << '\n';
}
