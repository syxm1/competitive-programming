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

  int n, p, q;
  cin >> n >> p >> q;

  map<int, int> memo;

  function<int(int)> f = [&](int x) -> int {
    if (x == 0) return 0; 
    if (memo.count(x)) return memo[x];

    int ret = x;

    if (x % 2 == 0) ret = min(ret, f(x / 2) + p);
    else ret = min(ret, f(x / 2) + p + 1);

    if (x % 3 == 0) ret = min(ret, f(x / 3) + q);
    else if (x % 3 == 1) ret = min(ret, f(x / 3) + q + 1);
    else ret = min(ret, f(x / 3) + q + 2);

    return memo[x] = ret;
  };

  while (n--) {
    int x;
    cin >> x;
    cout << f(x) << '\n';
  }
}
