#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, a, b, q;
  cin >> n >> m >> a >> b >> q;

  function<int(double)> cnt = [&](double mid) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
      ret += min((int) m, max(0ll, (int) (mid * (a + i)) - b));
    }
    return ret;
  };

  while (q--) {
    int l;
    cin >> l;

    double lo = 0, hi = 1e9, val = 0;

    for (int _ = 0; _ < 100; _++) {
      double md = (lo + hi) / 2.00;
      if (cnt(md) >= l) hi = md, val = md;
      else lo = md;
    }

    int num = 0, den = 1;

    for (int y = a + 1; y <= a + n; y++) {
      int x = val * y;
      if (x > b + m) continue;
      if (num * y < den * x) num = x, den = y;
    }

    int g = __gcd(num, den);
    
    cout << num / g << '/' << den / g << '\n';
  }
}
