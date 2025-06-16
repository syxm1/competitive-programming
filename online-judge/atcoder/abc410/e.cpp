#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int n, h, m;
int a[3005], b[3005], mxhp[3005][6005];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 3005; i++) {
    for (int j = 0; j < 6005; j++) {
      mxhp[i][j] = -1;
    }
  }

  cin >> n >> h >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      // base case
      if (i == 0) {
        if (j > b[i]) mxhp[i][j] = h;
        else if (h >= a[i]) mxhp[i][j] = h - a[i];
      }

      else {
        if (mxhp[i-1][j] >= a[i]) {
          mxhp[i][j] = mxhp[i-1][j] - a[i];
        } 
        if (mxhp[i - 1][j + b[i]] != -1) {
          mxhp[i][j] = max(mxhp[i][j], mxhp[i - 1][j + b[i]]);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      cout << mxhp[i][j] << ' ';
    }
    cout << '\n';
  }

  int ans = 0;
  for (; ans < n;) {
    bool found = 0;
    for (int j = 0; j < 6005; j++) {
      if (mxhp[ans][j] >= 0) {
        found = 1;
        break;
      }
    }
    if (found) ans++;
    else break;
  }

  cout << ans << '\n';
}
