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

    vector<int> a(n), b(n), c;
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    c = a;

    bool ok = a[n-1] == b[n-1];
    for (int i = n-2; i >= 0; i--) {
      if (a[i] != b[i]) a[i] ^= a[i+1];
      if (a[i] != b[i]) a[i] = (c[i] ^ c[i+1]);
      if (a[i] != b[i]) { ok = 0; break; }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
