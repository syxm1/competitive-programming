#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 1e5+5, inf = 1e16;
const int dir[] = {-1, 1};

int n, m, k, t, p, q;
vector<int> b[mxn], e[mxn];
vector<pair<int, int>> r[mxn];

bool inside(int x) {
    return x >= 0 && x < n;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> t >> p >> q;
    --p, --q;

    for (int i = 0; i < m; i++) {
        int u, v, w, x;
        cin >> u >> v >> w >> x;
        --u, --v;
        r[u].push_back({v, x});
        r[v].push_back({u, x});
        b[u].push_back(w);
        e[v].push_back(w);
    }

    multiset<int> s;

    for (int i = 0; i + 1 < n; i++) {
        for (int j : b[i]) {
            s.insert(j);
        }
        for (int j : e[i]) {
            s.erase(s.find(j));
        }
        if (!s.empty()) {
            r[i].push_back({i + 1, *s.begin()});
            r[i+1].push_back({i, *s.begin()});
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<int>> dist(n, vector<int>(2, inf));

    pq.push({0, p, 0});
    dist[p][0] = 0;
    dist[p][1] = inf;

    while (!pq.empty()) {
        auto [dis, cur, flag] = pq.top();
        pq.pop();
        if (dist[cur][flag] < dis) continue;
        for (auto [nxt, wei] : r[cur]) {
            int ticket = (flag == 0 ? t : 0);
            if (dist[nxt][1] > dis + wei + ticket) {
                dist[nxt][1] = dis + wei + ticket;
                pq.push(make_tuple(dist[nxt][1], nxt, 1));
            }
        }
        for (int d : dir) {
            if (inside(cur + d)) {
                if (dist[cur + d][0] > dis + k) {
                    dist[cur + d][0] = dis + k;
                    pq.push(make_tuple(dist[cur + d][0], cur + d, 0));
                }
            }
        }
    }

    cout << min(dist[q][0], dist[q][1]) << '\n';
}
