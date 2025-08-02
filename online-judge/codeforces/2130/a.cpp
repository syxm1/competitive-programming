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
    int n;
    cin >> n;

    vector<int> cnt(55);
    for (int i = 0; i < n; i++) {
      int s;
      cin >> s;
      cnt[s]++;
    }

    int ans = 0;
    for (int i = 2; i < 55; i++) {
     ans += cnt[i] * i; 
    }

    ans += min(cnt[0], cnt[1]) * 2;
    ans += cnt[0] - min(cnt[0], cnt[1]);
    ans += cnt[1] - min(cnt[0], cnt[1]);

    cout << ans << '\n';
  }
}
