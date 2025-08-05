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

  int n, q, sum = 0;
  cin >> n >> q;
  
  vector<int> a(n+1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  sort(a.begin(), a.end());
  reverse(a.begin() + 1, a.end());

  vector<int> ans(n+1, sum);

  for (int x = 1; x <= n; x++) {
    for (int i = x; i <= n; i += x) {
      ans[x] -= a[i] / 2;
    }
  }

  while (q--) {
    int x;
    cin >> x;
    if (x > n) cout << sum << '\n';
    else cout << ans[x] << '\n';
  }
}
