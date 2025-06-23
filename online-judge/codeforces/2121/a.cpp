#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, s;
    cin >> n >> s;  

    int mn = s, mx = s;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mn = min(mn, x);
      mx = max(mx, x);
    }

    int a = abs(s - mn) + (mx - mn);
    int b = abs(s - mx) + (mx - mn);

    cout << min(a, b) << '\n';
  }
}
