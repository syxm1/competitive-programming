#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int int64_t

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<vector<bool>> vis(n, vector<bool>(m, 0));
  stack<pair<int, int>> dfs;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] || v[i][j] == '#') continue;

      ans++;
      vis[i][j] = 1;
      dfs.push(make_pair(i, j));

      while (!dfs.empty()) {
        auto [x, y] = dfs.top();
        dfs.pop();

        for (int k = 0; k < 4; k++) {
          int xx = dx[k] + x, yy = dy[k] + y;

          if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
          if (vis[xx][yy] || v[xx][yy] == '#') continue;

          vis[xx][yy] = 1;
          dfs.push(make_pair(xx, yy));
        }
      }
    }
  }

  cout << ans << '\n';
}
