#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, x, ans;
    cin >> n >> x;

    int pop =__builtin_popcountll(x);
    if (x == 0) {
      if (n == 1) {
        ans = -1;
      } else if (n % 2 == 0) {
        ans = n;
      } else {
        ans = n + 3;
      }
    } else if (x == 1) {
      if (n & 1) {
        ans = n;
      } else {
        ans = n + 3;
      }
    } else {
      if (n <= pop) {
        ans = x;
      } else {
        int rem = n - pop;
        ans = x + rem;
        ans += (rem % 2 == 1);
      }
    }

    cout << ans << '\n';
  }
}
