#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> pref(n + 5, 0), mx(n + 5, 0);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i - 1];
      mx[i] = max(mx[i - 1], a[i - 1]);
    }

    for (int i = n; i > 0; i--) {
      cout << pref[n] - pref[i] + mx[i] << " \n"[i == 1];
    }
  }
}
