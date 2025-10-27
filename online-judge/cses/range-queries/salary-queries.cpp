#include <bits/stdc++.h>
using namespace std;
 
#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif
 
#define int long long
 
struct segtree {
  vector<int> tree;
 
  segtree(int n) : tree(4 * n, 0) {}
 
  void update(int v, int tl, int tr, int id, int val) {
    if (tl == tr) {
      tree[v] += val;
    } else {
      int tm = (tl + tr) >> 1;
      if (id <= tm) update(2 * v + 1, tl, tm, id, val);
      else update(2 * v + 2, tm + 1, tr, id, val);
      tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }
  }
 
  int get(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) {
      return tree[v];
    } else if (tr < l || r < tl) {
      return 0;
    } else {
      int tm = (tl + tr) >> 1;
      return get(2 * v + 1, tl, tm, l, r) + get(2 * v + 2, tm + 1, tr, l, r);
    }
  }
};

template<typename T> struct compressor {
  vector<T> v;

  compressor(const vector<T> &y) {
    v = y;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
  }

  int get(T x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  }

  int size() {
    return v.size();
  }
};
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n, q;
  cin >> n >> q;
 
  vector<int> p(n), a;
  vector<tuple<char, int, int>> query(q);
 
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    a.push_back(p[i]);
  }
 
  for (int i = 0; i < q; i++) {
    char u;
    int v, w;
    cin >> u >> v >> w;
    query[i] = make_tuple(u, v, w);
    a.push_back(w);
    if (u == '?') a.push_back(v);
  }
 
  compressor<int> c(a);
  for (auto &x : p) x = c.get(x);
  for (auto &[u, v, w] : query) {
    w = c.get(w);
    if (u == '?') v = c.get(v);
  }

  int m = c.size();
 
  segtree tree(m);
 
  for (int i = 0; i < n; i++) {
    tree.update(0, 0, m - 1, p[i], 1);
  }
 
  for (int i = 0; i < q; i++) {
    auto [u, v, w] = query[i];
    if (u == '!') {
      tree.update(0, 0, m - 1, p[v - 1], -1);
      tree.update(0, 0, m - 1, w, 1);
      p[v - 1] = w;
    } else {
      cout << tree.get(0, 0, m - 1, v, w) << '\n';
    }
  }
}
