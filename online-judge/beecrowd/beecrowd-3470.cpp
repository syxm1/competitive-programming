// Game of &

/*
menggunakan A* search untuk mencari jalan terpendek menuju final state.
fungsi heuristic:
f(n) = g(n) + h(n)
dimana:
f(n) : fungsi heuristic
g(n) : jarak dari state awal (berapa operasi yang sudah dilakukan).
h(n) : estimasi jarak dari state akhir. 
*/

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

#define pad vector<vector<int>>

vector<pair<int, int>> pos(9); 
pad start(3, vector<int>(3));

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool solvable(pad v) {
    int inv = 0;
    vector<int> a;
    for (int i = 0; i < 3; i++) {
        for (int x : v[i]) {
            a.push_back(x);
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            inv += (a[j] < a[i] && a[i] && a[j]);
        }
    }
    return !(inv&1);
}

int dist(pad v) {
    int ret = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret += (pos[v[i][j]] != make_pair(i, j) && v[i][j] != 0);
        }
    }
    return ret;
}

bool inside(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

int a_star(pad v) {
    if (!solvable(v)) return -1;

    auto cmp = [&] (tuple<int, int, int, int, pad> &a, tuple<int, int, int, int, pad> &b) {
        return get<0>(a) + get<1>(a) > get<0>(b) + get<1>(b);
    };

    priority_queue<tuple<int, int, int, int, pad>, vector<tuple<int, int, int, int, pad>>, decltype(cmp)> pq(cmp);

    int oi, oj;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (v[i][j] == 0) oi = i, oj = j; 
        }
    }

    pq.push({0, dist(v), oi, oj, v});

    while (!pq.empty()) {
        auto [g, h, i, j, p] = pq.top();
        pq.pop();

        if (h == 0) {
            return g;
        }

        for (int k = 0; k < 4; k++) {
            if (inside(i + dx[k], j + dy[k])) {
                pad q = p;
                swap(q[i][j], q[i+dx[k]][j+dy[k]]);
                int ndist = dist(q);
                pq.push({g + 1, ndist, i + dx[k], j + dy[k], q});
            }
        }
    }

    return -1;
}

signed main() {
    pos[1] = {0, 0};
    pos[2] = {0, 1};
    pos[3] = {0, 2};
    pos[4] = {1, 0};
    pos[5] = {1, 1};
    pos[6] = {1, 2};
    pos[7] = {2, 0};
    pos[8] = {2, 1};
    pos[0] = {2, 2};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> start[i][j];
        }
    }

    cout << a_star(start) << '\n';
}
