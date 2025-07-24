#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int int64_t

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const char dir[4] = {'R', 'L', 'D', 'U'};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> v(n);

  pair<int, int> human;
  vector<pair<int, int>> monsters;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 'A') human = make_pair(i, j);
      if (v[i][j] == 'M') monsters.push_back(make_pair(i, j));
    }
  }

  vector<vector<int>> human_distance(n, vector<int>(m, 1e15));
  vector<vector<int>> monster_distance(n, vector<int>(m, 1e15));

  queue<pair<int, int>> bfs;

  for (auto monster : monsters) {
    monster_distance[monster.first][monster.second] = 0;
    bfs.push(monster);
  }

  while (!bfs.empty()) {
    auto [x, y] = bfs.front();
    bfs.pop();

    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (v[xx][yy] == '#') continue;

      if (monster_distance[xx][yy] > monster_distance[x][y] + 1) {
        monster_distance[xx][yy] = monster_distance[x][y] + 1;
        bfs.push(make_pair(xx, yy));
      }
    }
  }

  vector<vector<pair<int, int>>> prev_step(n, vector<pair<int, int>>(m, {-1, -1}));

  human_distance[human.first][human.second] = 0;
  bfs.push(human);

  pair<int, int> finish = {-1, -1};

  if (human.first == 0 || human.first == n - 1 || human.second == 0 || human.second == m - 1) {
    finish = human;
  }

  while (!bfs.empty() && finish.first == -1) {
    auto [x, y] = bfs.front();
    bfs.pop();

    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (v[xx][yy] == '#') continue;

      if (human_distance[xx][yy] > human_distance[x][y] + 1) {
        human_distance[xx][yy] = human_distance[x][y] + 1;
        if (monster_distance[xx][yy] > human_distance[xx][yy]) {
          bfs.push({xx, yy});
          prev_step[xx][yy] = {x, y};
          if (xx == 0 || xx == n - 1 || yy == 0 || yy == m - 1) {
            finish = {xx, yy};
            goto end_bfs; 
          }
        }
      }
    }
  }

end_bfs:; 
  if (finish.first == -1) {
    cout << "NO\n";
    return 0;
  }

  string path = "";
  pair<int, int> cur_node = finish;

  while (cur_node != human) {
    auto [px, py] = prev_step[cur_node.first][cur_node.second];
    if (cur_node.first == px + 1) path += 'D';
    else if (cur_node.first == px - 1) path += 'U';
    else if (cur_node.second == py + 1) path += 'R';
    else if (cur_node.second == py - 1) path += 'L';
    cur_node = {px, py};
  }

  reverse(path.begin(), path.end());

  cout << "YES\n";
  cout << path.length() << '\n';
  cout << path << '\n';
}
