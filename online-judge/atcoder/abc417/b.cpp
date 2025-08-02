#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  map<int, int> cnt;

  for (int i = 0; i < n; i++) {
    int x; cin >> x; cnt[x]++;
  }

  for (int i = 0; i < m; i++) {
    int x; cin >> x; cnt[x] = max(cnt[x] - 1, 0ll);
  }

  for (auto [i, j] : cnt) {
    for (int k = 0; k < j; k++) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}
