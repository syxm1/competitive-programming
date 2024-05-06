// Awesome Arrowland Adventure

#include<bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const char cc[] = {'N', 'E', 'S', 'W'};

int n, m;
vector<string> grid;
vector<vector<int>> dist;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int val(char c) {
	if (c == 'N') return 1;
	if (c == 'E') return 2;
	if (c == 'S') return 3;
	if (c == 'W') return 4;
	return 0;
}

int rot(char a, char b) {
	return (val(b) - val(a) + 4) % 4;
}

bool inside(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

signed main() {
	cin >> n >> m;

	grid.resize(n);
	dist.assign(n, vector<int>(m, 1000000000));

	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	pq.push({0,0,0});

	while (!pq.empty()) {
		auto [d, x, y] = pq.top();
		pq.pop();

		if (grid[x][y] == 'X') continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i], c = cc[i];
			if (inside(nx, ny) && dist[nx][ny] > d + rot(grid[x][y], c)) {
				dist[nx][ny] = d + rot(grid[x][y], c);
				pq.push({dist[nx][ny], nx, ny});
			}
		}
	}

	cout << (dist[n-1][m-1] == 1e9 ? -1 : dist[n-1][m-1]) << '\n';
}
