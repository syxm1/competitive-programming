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

  int tc;
  cin >> tc;

  while (tc--) {
    int n, k;
    cin >> n >> k;

    vector<int> s(n), t(n);
    for (int &i : s) cin >> i;
    for (int &i : t) cin >> i;

    unordered_map<int, int> cnt;
    for (int i : t) cnt[i%k]++, cnt[k-(i%k)]++;
    for (int i : s) cnt[i%k]--, cnt[k-(i%k)]--;

    bool ok = 1;
    for (auto [p, q] : cnt) {
      if (q != 0) ok = 0;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
