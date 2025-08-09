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

  int n;
  cin >> n;

  string s;
  cin >> s;

  if (n < 3 || s[n-1] != 'a' || s[n-2] != 'e' || s[n-3] != 't') cout << "No\n";
  else cout << "Yes\n";
}
