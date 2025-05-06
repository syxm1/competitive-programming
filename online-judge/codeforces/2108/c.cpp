#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }

    int ans = 1, dir;
    
    if (a[1] >= a[0]) {
      dir = 1;
    } else if (a[1] < a[0]){
      dir = -1;
    } 

    for (int i = 2; i < n; i++) {
      if (dir == -1 && a[i] > a[i-1]) {
        ans++, dir = 1;
        continue;
      }
      if (a[i] < a[i-1]) {
        dir = -1;
      }
    }

    cout << ans << '\n';
  }
}
