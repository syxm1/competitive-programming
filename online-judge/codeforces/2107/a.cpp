#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    bool same = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[0]) {
        same = 0;
        break;
      }
    }

    if (same) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      int mx = *max_element(a.begin(), a.end());
      for (int i = 0; i < n; i++) {
        if (a[i] == mx) cout << 1 << ' ';
        else cout << 2 << ' ';
      }
      cout << '\n';
    }
  }
}
