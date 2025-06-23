#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (1) {
    cout << n << ' ';
    if (n == 1) break;
    if (n & 1) n = n * 3 + 1;
    else n = n / 2;
  }

  cout << '\n';
}
