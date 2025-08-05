#include <bits/stdc++.h>
using namespace std;

#define int int64_t

string s;
int n, m, k, p, q;
vector<int> fin;
vector<vector<int>> arr;
vector<vector<bool>> vis;

void traverse(int cur_x, int cur_y, int cur_m) {
  if (cur_x == n - 1 && cur_y == m - 1) {
    fin.push_back(cur_m);
    return;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s >> n >> m;

  arr.assign(n, vector<int>(m));
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      cin >> arr[x][y];
    }
  }

  traverse(0, 0, 0);
  sort(fin.begin(), fin.end());

  cin >> k;
  while (k--) {
    cin >> p >> q;
  }
}
