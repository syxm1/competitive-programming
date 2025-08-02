#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<pair<pii, int>> v;
    for (int i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      v.push_back(mp(mp(a, b), i));
    }

    sort(v.begin(), v.end(), [](pair<pii, int> &a, pair<pii, int> &b) {
        return (a.fi.fi == b.fi.fi ? a.fi.se > b.fi.se : a.fi.fi < b.fi.fi);
        });

    vector<int> ans;
    ans.push_back(v[0].se);

    int r = v[0].fi.se;
    for (int i = 1; i < n; i++) {
      if (v[i].fi.se > r) {
        ans.push_back(v[i].se);
        r = v[i].fi.se;
      }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
  }
}
