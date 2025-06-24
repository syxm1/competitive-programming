#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<bool> a(n+1, 0);
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    a[x] = 1;
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      cout << i << '\n';
      break;
    }
  }
}
