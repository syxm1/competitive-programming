#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int s;
    cin >> s;

    int root = sqrt(s);
    if (s == 0) {
      cout << 0 << ' ' << 0 << '\n';
    }
    else if (root * root == s) {
      cout << 1 << ' ' << (root - 1) << '\n';
    }
    else {
      cout << -1 << '\n';
    }
  }
}
