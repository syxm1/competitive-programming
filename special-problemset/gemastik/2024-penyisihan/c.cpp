#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

vector<int> par, sz;

int get(int x) {
  return par[x] = x == par[x] ? x : get(par[x]);
}

void merge(int x, int y) {
  x = get(x);
  y = get(y);
  if (x != y) {
    if (sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  par.resize(n);
  iota(par.begin(), par.end(), 0);
  sz.assign(n, 1);

  vector<bool> solo(n, 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    solo[u] = 0;
    solo[v] = 0;
    merge(u, v);
  }

  int ans = 0, cntsolo = 0;
  for (int i = 0; i < n; i++) {
    if (!solo[i]) ans += (par[i] == i);
    else cntsolo++;
  }

  ans += cntsolo > 1;

  cout << ans << '\n';
}
