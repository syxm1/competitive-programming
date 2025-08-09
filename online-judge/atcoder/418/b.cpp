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

  cout << fixed << setprecision(10);

  string s;
  cin >> s;

  int n = s.length();
  double ans = 0;

  for (int i = 0; i + 2 < n; i++) {
    if (s[i] != 't') continue;
    int cnt = 1;
    if (s[i + 1] == 't') cnt++;
    for (int j = i + 2; j < n; j++) {
      if (s[j] != 't') continue;
      cnt++;
      int len = j - i + 1;
      double can = (cnt - 2.00) / (len - 2.00);
      trace(i);
      trace(j);
      trace(cnt);
      trace(len);
      trace(can);
      ans = max(ans, can);
    }
  }

  cout << ans << '\n';
}
