#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

struct segtree {
  int size;
  vector<int> tree;

  segtree(int n) {
    size = n;
    tree.resize(4 * n);
  }

  void update(int v, int tl, int tr, int id, int val) {
    if (tl == tr) {
      tree[v] += 1;
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

  int n;
  cin >> n;

  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }

  compressor<int> c(a);
  for (int &i : a) {
    i = c.get(i);
  }

  int m = c.size();
  segtree tree1(m), tree2(m);

  vector<int> inv(n, 0);
  for (int i = 0; i < n; i++) {
    inv[i] = tree1.get(0, 0, m - 1, a[i] + 1, m - 1);
    tree1.update(0, 0, m - 1, a[i], 1);
  }

  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int cur = tree2.get(0, 0, m - 1, 0, a[i] - 1);
    ans += cur * inv[i];
    tree2.update(0, 0, m - 1, a[i], 1);
  }

  cout << ans << '\n';
}
