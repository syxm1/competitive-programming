#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int c2(int n) {
  return (int) (n - 1ll) * n / 2ll;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int S = c2(i * i); // sets
    int C = 4 * (i - 1) * (i - 2); // complements
    cout << S - C << '\n';
  }
}
