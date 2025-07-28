#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int int64_t
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

const bool operator!=(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first != b.first || a.second != b.second;
}

const bool operator==(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first == b.first && a.second == b.second;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> v(n);
  pair<int, int> start, end;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 'A') start = mp(i, j);
      if (v[i][j] == 'B') end = mp(i, j);
    }
  }

  vector<vector<pii>> prev(n, vector<pii>(m, mp(-1, -1)));
  queue<pii> bfs;

  prev[start.fi][start.se] = start;
  bfs.push(start);


  while (!bfs.empty()) {
    auto [cur_x, cur_y] = bfs.front();
    bfs.pop();

    for (int i = 0; i < 4; i++) {
      int nxt_x = cur_x + dx[i];
      int nxt_y = cur_y + dy[i];

      if (nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= m) continue;
      if (v[nxt_x][nxt_y] == '#' || prev[nxt_x][nxt_y] != mp(-1, -1)) continue;

      prev[nxt_x][nxt_y] = mp(cur_x, cur_y);
      bfs.push(mp(nxt_x, nxt_y));
    }
  }

  if (prev[end.fi][end.se] == mp(-1, -1)) {
    cout << "NO\n";
    return 0;
  }

  string ans = "";
  pii cur = end;

  while (cur != start) {
    pii pre = prev[cur.fi][cur.se];
    if (pre.fi + 1 == cur.fi) ans.push_back('D');
    else if (pre.fi - 1 == cur.fi) ans.push_back('U');
    else if (pre.se + 1 == cur.se) ans.push_back('R');
    else if (pre.se - 1 == cur.se) ans.push_back('L');
    cur = pre;
  }

  reverse(ans.begin(), ans.end());

  cout << "YES\n" << ans.length() << '\n' << ans << '\n';
}
