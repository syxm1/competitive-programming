#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << '\n';
  } else if (n == 2 || n == 3) {
    cout << "NO SOLUTION\n";
  } else {
    for (int i = n, j = (n + 1) / 2, id = 0; id < n; id++) {
      if (id & 1) cout << i-- << ' ';
      else cout << j-- << ' ';
    }
    cout << '\n';
  }
}
