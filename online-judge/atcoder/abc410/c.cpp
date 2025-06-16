#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  iota(a.begin(), a.end(), 1);

  int shift = 0;

  while (q--) {
    int op;
    cin >> op;

    if (op == 1) {
      int p, x;
      cin >> p >> x;
      --p;
      a[(p + shift) % n] = x;
    }

    else if (op == 2) {
      int p;
      cin >> p;
      --p;
      cout << a[(p + shift) % n] << '\n';
    } 

    else {
      int k;
      cin >> k;
      shift += k;
      shift %= n;
    }
  }
}
