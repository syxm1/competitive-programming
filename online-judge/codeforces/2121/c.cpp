#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> left_top(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> right_top(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> left_bottom(n + 5, vector<int>(m + 5, 0));
    vector<vector<int>> right_bottom(n + 5, vector<int>(m + 5, 0));
    vector<int> row(n + 5, 0);
    vector<int> col(m + 5, 0);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        row[i] = max(row[i], a[i][j]);
        col[j] = max(col[j], a[i][j]);
      }
    }
    
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        left_top[i][j] = max({a[i][j], left_top[i-1][j], left_top[i][j-1]});
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = m; j >= 1; j--) {
        right_top[i][j] = max({a[i][j], right_top[i-1][j], right_top[i][j+1]});
      }
    }

    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= m; j++) {
        left_bottom[i][j] = max({a[i][j], left_bottom[i+1][j], left_bottom[i][j-1]});
      }
    }

    for (int i = n; i >= 1; i--) {
      for (int j = m; j >= 1; j--) {
        right_bottom[i][j] = max({a[i][j], right_bottom[i+1][j], right_bottom[i][j+1]});
      }
    }

    int ans = 1e9;
    
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ans = min(ans, max({left_top[i-1][j-1], right_top[i-1][j+1], left_bottom[i+1][j-1], right_bottom[i+1][j+1], row[i] - 1, col[j] - 1}));
      }
    }

    cout << ans << '\n';
  }
}
