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

  map<int, int> cnt;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans += cnt[i - a];
    cnt[a + i]++;
  }
  
  cout << ans << '\n';
}
