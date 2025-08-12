#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    if (n == 2) {
      cout << -1 << ' ' << 2 << '\n';
    } else {
      for (int i = 0; i < n - 1; i++) {
        cout << (i & 1 ? 3 : -1) << ' ';
      }
      if (n & 1) cout << -1;
      else cout  << 2;
      cout << '\n';
    }
  }
}
