#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << ((a + b) % 3 == 0 && abs(a - b) <= min(a, b) ? "YES\n" : "NO\n");
  }
}
