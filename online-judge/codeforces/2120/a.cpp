#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int l[3], b[3], lt = 0, bt = 0;
    for (int i = 0; i < 3; i++) {
      cin >> l[i] >> b[i];
      lt += l[i];
      bt += b[i];
    }

    bool case1 = 0, case2 = 0, case3 = 0, case4 = 0;
    if (l[0] == b[0] + b[1] + b[2] && l[0] == l[1] && l[0] == l[2]) case1 = 1;
    if (b[0] == l[0] + l[1] + l[2] && b[0] == b[1] && b[0] == b[2]) case2 = 1;
    for (int i = 0; i < 3; i++) {
      int j = (i + 1) % 3;
      int k = (i + 2) % 3;
      if (l[i] * 2 == lt && l[i] == b[i] + b[j] && b[j] == b[k]) case3 = 1;
      if (b[i] * 2 == bt && b[i] == l[i] + l[j] && l[j] == l[k]) case4 = 1;
    }

    cout << (case1 || case2 || case3 || case4 ? "yes" : "no") << '\n';
  }
}
