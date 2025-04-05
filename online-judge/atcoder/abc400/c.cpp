#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int ans = 0;

  for (int a = 1; (1 << a) <= n && a <= 2; a++) {
    int lo = 0, hi = 1e9, bmax = 0;
    while (lo <= hi) {
      int md = (lo + hi) >> 1;
      if (md * md * (1 << a) <= n) {
        bmax = md, lo = md + 1;
      } else {
        hi = md - 1;
      }
    }
    ans += bmax;
  }

  cout << ans << '\n';
}
