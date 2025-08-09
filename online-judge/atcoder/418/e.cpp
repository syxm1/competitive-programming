#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second

pii slope(pii a, pii b) {
  int x = a.first - b.first;
  int y = a.second - b.second;
  if (x == 0) return mp(1e18, 1e18);
  if (y == 0) return mp(0, 0);
  int g = __gcd(abs(y), abs(x));
  y /= g, x /= g;
  if (y < 0) y *= -1, x *= -1;
  return mp(y, x);
}

pii mid(pii a, pii b) {
  int x = a.first + b.first;
  int y = a.second + b.second;
  return mp(x, y);
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        size_t hash1 = hash<T1>{}(p.first);
        size_t hash2 = hash<T2>{}(p.second);
        return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
    }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pii> points(n);
  for (int i = 0; i < n; i++) {
    cin >> points[i].fi >> points[i].se;
  }

  unordered_map<pii, int, hash_pair> cnt_slopes, cnt_mids;

  int ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto cur_slope = slope(points[i], points[j]);      
      auto cur_mid = mid(points[i], points[j]);
      cnt_slopes[cur_slope]++, cnt_mids[cur_mid]++; 
    }
  }

  for (auto [p, q] : cnt_slopes) ans += q * (q - 1) / 2;
  for (auto [p, q] : cnt_mids) ans -= q * (q - 1) / 2;

  cout << ans << '\n';
}
