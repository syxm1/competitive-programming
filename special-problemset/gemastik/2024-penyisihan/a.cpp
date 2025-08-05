#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

int ceildiv(int a, int b) {
  return (a + b - 1) / b;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans;
  if (b == 0 && c == 0) ans = ceildiv(a + d, 3);
  else if (b == 0) ans = ceildiv(a + c, 3) + ceildiv(d, 3);
  else if (c == 0) ans = ceildiv(a, 3) + ceildiv(b + d, 3);
  else ans = ceildiv(a, 3) + ceildiv(b + c, 3) + ceildiv(d, 3);
  cout << ans << '\n';
}
