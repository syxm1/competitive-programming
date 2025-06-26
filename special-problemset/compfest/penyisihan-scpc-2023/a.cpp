#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int ans = 1e9;
  
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans = min(ans, abs(x));
  }

  cout << ans << '\n';
}
