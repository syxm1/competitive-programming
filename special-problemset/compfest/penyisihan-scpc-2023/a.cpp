#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, ans = 1e9;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    ans = min(ans, abs(a));
  }

  cout << ans << '\n';
}
