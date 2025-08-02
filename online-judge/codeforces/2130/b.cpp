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

  int t;
  cin >> t;

  while (t--) {
    int n, s;
    cin >> n >> s;

    int sum = 0, cnt[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      sum += a, cnt[a]++;
    }

    if (s == sum || (s - sum) > 1) {
      cout << -1 << '\n';
      continue;
    }

    for (int i = 0; i < cnt[0]; i++) cout << 0 << ' ';
    for (int i = 0; i < cnt[2]; i++) cout << 2 << ' ';
    for (int i = 0; i < cnt[1]; i++) cout << 1 << ' ';
    cout << '\n';
  }
}
