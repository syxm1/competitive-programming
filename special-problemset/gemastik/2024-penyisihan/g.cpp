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

  int n;
  cin >> n;

  vector<int> a(n + 5), b(n + 5);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = n; i >= 1; i--) b[i] = max(b[i + 1], b[i]);

  int ans = 0;
  for (int i = 1; i + 2 <= n; i++) {
    ans = max(ans, b[i + 2] - a[i]);
  }

  if (ans) cout << ans << '\n';
  else cout << "tidak mungkin\n";
}
