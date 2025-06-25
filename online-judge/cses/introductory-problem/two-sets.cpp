#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n % 4 == 3) {
    cout << "YES\n";

    int l = 4, r = n, cnt = 0;
     
    cout << (n + 1) / 2 << '\n';
    cout << 1 << ' ' << 2 << ' '; cnt += 2;
    if (n > 3) {
      for (;;) {
        cnt += 2;
        cout << l++ << ' ' << r-- << " \n"[cnt == (n + 1) / 2];
        if (cnt == (n + 1) / 2) break;
      }
    }

    cout << (n - 1) / 2 << '\n';
    cout << 3 << ' '; cnt++;
    if (n > 3) {
      for (;;) {
        cnt += 2;
        cout << l++ << ' ' << r-- << " \n"[cnt == n];
        if (cnt == n) break;
      }
    }

    return 0;
  } 

  if (n % 4 == 0) {
    cout << "YES\n";

    int l = 1, r = n, cnt = 2;

    cout << n / 2 << '\n';
    for (; cnt <= n / 2; l++, r--, cnt += 2) {
      cout << l << ' ' << r << " \n"[cnt == n / 2];
    }

    cout << n / 2 << '\n';
    for (; cnt <= n; l++, r--, cnt += 2) {
      cout << l << ' ' << r << " \n"[cnt == n];
    }

    return 0;
  }

  cout << "NO\n";
}
