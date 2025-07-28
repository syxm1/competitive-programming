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

    int id = -1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i > 0 && a[i] < a[i - 1]) {
        id = i;
      }
    }

    if (id != -1) {
      cout << "YES\n";
      cout << 2 << '\n';
      cout << a[id - 1] << ' ' << a[id] << '\n';
    } else {
      cout << "NO\n";
    }
  }
}

/*
 * 4 5 5 2 4
 * 2 4 4 5 5
 *
 * 4 8 3 1
 * 1 3 4 8
 *
 * 5 6 7 8 9 -> no
 *
 * 9 8 7 6 5 -> yes
 * 9 8 6 5
 * 5 6 8 9
 *
 * 
 */
