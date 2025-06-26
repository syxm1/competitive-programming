#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mod = 998244353;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  int m;
  cin >> m;

  vector<int> c(m), d(m);
  for (int i = 0; i < m; i++) cin >> c[i];
  for (int i = 0; i < m; i++) cin >> d[i];


  vector<int> x(2e6+5, 0), y(2e6+5, 0);
  
  for (int i = 0; i < n; i++) x[a[i]] = b[i];
  for (int i = 0; i < m; i++) y[c[i]] = d[i];

  int ans = 1;

  for (int i = 2; i < 2e6+5; i++) {
    if (x[i] < y[i]) {
      ans = 0;
      break;
    }
    if (x[i] > y[i]) {
      ans *= 2;
      ans %= mod;
    }
  }

  cout << ans << '\n';
}
