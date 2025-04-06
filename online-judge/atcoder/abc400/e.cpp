#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mxn = 1e6+1;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> spf(mxn, -1);

  spf[1] = 1;
  for (int i = 2; i < mxn; i++) {
    if (spf[i] != -1)
      continue;
    spf[i] = i;
    for (int j = i * i; j < mxn; j += i) {
      spf[j] = i;
    }
  }

  vector<int> ell;

  for (int i = 2; i < mxn; i++) {
    int j = i;
    set<int> factors;
    while (j > 1) {
      factors.insert(spf[j]);
      j /= spf[j];
    }
    if ((int)factors.size() == 2) {
      ell.push_back(i);
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int a;
    cin >> a;

    int lo = 0, hi = ell.size() - 1, ans = ell[0] * ell[0];
    while (lo <= hi) {
      int md = (lo + hi) >> 1;
      // cout << md << ' ' << ell[md] << '\n';
      if (ell[md] * ell[md] <= a) {
        ans = ell[md] * ell[md];
        lo = md + 1;
      } else {
        hi = md - 1;
      }
    }

    cout << ans << '\n';
  }
}

