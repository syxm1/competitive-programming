#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, k, sum = 0;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    if (mx - mn - 1 > k) {
      cout << "Jerry\n";
    } else {
      if (sum & 1) cout << "Tom\n";
      else cout << "Jerry\n";
    }
  }
}

// k = 1; a = 2 1 3; winner = Jerry
