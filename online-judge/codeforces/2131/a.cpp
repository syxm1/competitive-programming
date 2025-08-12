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

    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    
    int ans;
    for (ans = 1;;ans++) {
      bool found = 0;
      for (int i = 0; i < n; i++) if (a[i] > b[i]) { a[i]--, found = 1; break; }
      if (!found) break;
      for (int i = 0; i < n; i++) if (a[i] < b[i]) { a[i]++; break; }
    }

    cout << ans << '\n';
  }
}
