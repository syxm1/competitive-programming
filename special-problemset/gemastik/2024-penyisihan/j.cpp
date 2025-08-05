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

  int mx = 0, mn = 1e9+5;
  bool same = 1;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != a[0]) same = 0;
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }

  int gema = 0, astik;

  sort(a.begin(), a.end());

  for (int i = 1; i < n; i++) {
    gema = max(gema, a[i] - a[i - 1]);
  }

  astik = (same ? 0 : mx - mn);

  cout << gema << '\n' << astik << '\n';
}
