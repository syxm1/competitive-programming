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
    int n, x;
    cin >> n >> x;

    vector<char> v(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
    }

    int kiri = 0, kanan = n + 1;
    for (int i = x - 1; i > 0; i--) {
      if (v[i] == '#') {
        kiri = i;
        break;
      }
    }

    for (int i = x + 1; i <= n; i++) {
      if (v[i] == '#') {
        kanan = i;
        break;
      }
    }

    if (kiri == 0 && kanan == n + 1) {
      cout << 1 << '\n';
      continue;
    }

    int dist_kiri = kiri + 1;
    int dist_kanan = n + 2 - kanan;

    if (dist_kiri < dist_kanan) {
      cout << min(x, dist_kanan) << '\n';
    } else {
      cout << min(dist_kiri, n + 1 - x) << '\n';
    }
  }
}
