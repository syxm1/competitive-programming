#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  int ans = 0;

  for (int i = 1; i < n ;i++) {
    if (x[i] < x[i - 1]) {
      ans += x[i - 1] - x[i];
      x[i] = x[i - 1];
    }
  }

  cout << ans << '\n';
}
