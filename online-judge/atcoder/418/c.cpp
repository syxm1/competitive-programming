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

  int n, q;
  cin >> n >> q;

  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  vector<int> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  while (q--) {
    int b;
    cin >> b;
    
    if (b > a.back()) {
      cout << -1 << '\n';
      continue;
    }

    int lo = 0, hi = n, id = 0;
    while (lo <= hi) {
      int md = (lo + hi) >> 1;
      if (a[md] < b - 1) {
        lo = md + 1;
        id = md;
      } else {
        hi = md - 1;
      }
    }

    int ans = pref[id] + (n - id) * (b - 1) + 1;
    cout << ans << '\n';
  }
}
