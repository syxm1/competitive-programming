#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int k;
  cin >> k;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += (a[i] >= k);
  } 
  
  cout << cnt << '\n';
}
