#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int ans = 1, num = 1;

  for (int i = 0; i < m; i++) {
    num *= n;
    ans += num;
    if (ans < 0 || ans > 1e9) {
      cout << "inf" << '\n';
      return 0;
    }
  }

  cout << ans << '\n';
}
