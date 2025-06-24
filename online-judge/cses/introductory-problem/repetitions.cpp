#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int ans = 1, cur = 1;
  
  for (int i = 1; i < (int) s.length(); i++) {
    (s[i] == s[i - 1]) ? (cur++) : (cur = 1);
    ans = max(ans, cur);
  }

  cout << ans << '\n';
}
