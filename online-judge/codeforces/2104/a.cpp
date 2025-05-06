#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((b - a) <= (c - b) && (c - 2 * b + a) % 3 == 0 ? "YES\n" : "NO\n"); 
  }
}
