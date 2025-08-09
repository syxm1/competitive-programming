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

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first;
    for (int i = 0; i < n; i++) cin >> v[i].second;
    for (int i = 0; i < n; i++) {
      if (v[i].first < v[i].second) swap(v[i].first, v[i].second);
    }

    sort(v.begin(), v.end());

    // for (int i = 0; i < n; i++) cout << v[i].first << ' '; cout << '\n';
    // for (int i = 0; i < n; i++) cout << v[i].second << ' '; cout << '\n';
    //
    
    int sum = 0;

    for (int i = 0; i < n; i++) {
      sum += v[i].first - v[i].second;
    }

    int min_add = 1e18;

    for (int i = 1; i < n; i++) {
      vector<int> x = {v[i].first, v[i].second, v[i-1].first, v[i-1].second};
      int cur = abs(v[i].first - v[i].second) + abs(v[i-1].first - v[i-1].second);
      int can = abs(x[3] - x[0]) + abs(x[2] - x[1]);
      min_add = min(min_add, can - cur);
    }

    cout << sum + min_add << '\n';
  }
}
