#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x, y;
    cin >> x >> y;
    
    int layer = max(x, y);
    int ans = (layer - 1) * (layer - 1);

    if (layer & 1) {
      if (x < y) ans += 2 * layer - x;
      else ans += y;
    } else {
      if (x < y) ans += x;
      else ans += 2 * layer - y;
    }

    cout << ans << '\n';
  }
}
