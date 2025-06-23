#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int g1(int x, int y) {
  return x - y;
}

int g2(int x, int y) {
  return x + y;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, s;
    cin >> n >> s;

    int ans = 0;
    int d1 = g1(0, 0);
    int d2 = g2(s, 0);

    vector<int> dx(n), dy(n), x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> dx[i] >> dy[i] >> x[i] >> y[i];
      bool case1 = g1(x[i], y[i]) == d1 && (dx[i] == dy[i]);
      bool case2 = g2(x[i], y[i]) == d2 && (dx[i] != dy[i]);
      ans += (case1 || case2);
    }

    cout << ans << '\n';
  }
}
