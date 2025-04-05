#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
int h, w;

bool inside(int x, int y) { return x >= 0 && x < h && y >= 0 && y < w; }

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> h >> w;

  vector<string> v(h);
  for (int i = 0; i < h; i++) {
    cin >> v[i];
  }

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  --a, --b, --c, --d;

  priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>,
                 greater<>>
      pq;
  vector<vector<int>> kick(h, vector<int>(w, 1e9));

  pq.push(make_tuple(0, (abs(c - a) + abs(d - b)), a, b));
  kick[a][b] = 0;

  while (!pq.empty()) {
    auto [cur_kick, cur_dist, x, y] = pq.top();
    pq.pop();
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 2; j++) {
        int new_kick = 0, xx = x + dx[i] * j, yy = y + dy[i] * j;
        if (!inside(xx, yy))
          break;
        for (int k = 1; k <= j; k++) {
          if (v[x + dx[i] * k][y + dy[i] * k] == '#')
            new_kick = 1;
        }
        new_kick += cur_kick;
        if (kick[xx][yy] > new_kick) {
          kick[xx][yy] = new_kick;
          pq.push(make_tuple(new_kick, abs(c - xx) + abs(d - yy), xx, yy));
        }
      }
    }
  }

  cout << kick[c][d] << '\n';
}
