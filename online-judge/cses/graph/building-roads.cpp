#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int int64_t

int n, m;
vector<int> par, sz;

int get(int u) {
  return par[u] = (par[u] == u ? u : get(par[u]));
}

void merge(int u, int v) {
  u = get(u);
  v = get(v);
  if (u != v) {
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  par.resize(n);
  iota(par.begin(), par.end(), 0);
  sz.assign(n, 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    merge(--u, --v);
  }

  vector<int> ans;

  for (int i = 0; i < n; i++) {
    if (par[i] == i) {
      ans.push_back(i);
    }
  }

  cout << ans.size() - 1 << '\n';
  for (int i = 1; i < (int) ans.size(); i++) {
    cout << ans[i - 1] + 1 << ' ' << ans[i] + 1 << '\n';
  }
}
