// Cab Driver Route

/*
dijkstra untuk menghitung jarak terpendek dari node 0 dan tiap2 node yang ada di list order.
dp bitmask untuk menentukan urutan yang paling efektif untuk memenuhi semua order.
*/

#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int inf = 2e9;

int n, m, k;
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> ord;

map<int, vector<int>> dist;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void get_dist(int source) {
    dist[source].resize(n);
    for (int i = 0; i < n; i++) {
        dist[source][i] = inf;
    }

    pq.push({0, source});
    dist[source][source] = 0;

    while (!pq.empty()) {
        auto [d, c] = pq.top();
        pq.pop();

        for (auto [s, w] : adj[c]) {
            if (d + w < dist[source][s]) {
                dist[source][s] = d + w;
                pq.push({d + w, s});
            }
        }
    }
}

signed main() {
    cin >> n >> m >> k;

    adj.resize(n);
    ord.resize(k);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    get_dist(0);

    for (int i = 0; i < k; i++) {
        cin >> ord[i].fi >> ord[i].se;
        ord[i].fi--, ord[i].se--;
        get_dist(ord[i].fi);
        get_dist(ord[i].se);
    }

    vector<vector<int>> dp(k, vector<int>(1 << k, inf));

    for (int i = 0; i < k; i++) {
        dp[i][1 << i] = dist[0][ord[i].fi] + dist[ord[i].fi][ord[i].se];
    }

    for (int mask = 1; mask < (1 << k); mask++) {
        for (int cur = 0; cur < k; cur++) {
            if (mask & (1 << cur)) {
                for (int nxt = 0; nxt < k; nxt++) {
                    if (!(mask & (1 << nxt))) {
                        int nxt_mask = mask | (1 << nxt);
                        dp[nxt][nxt_mask] = min(dp[nxt][nxt_mask], dp[cur][mask] + dist[ord[cur].se][ord[nxt].fi] + dist[ord[nxt].fi][ord[nxt].se]); 
                    }   
                }
            }
        }
    }

    int ans = inf;

    for (int i = 0; i < k; i++) {
        ans = min(ans, dp[i][(1 << k) - 1] + dist[ord[i].se][0]);
    }

    cout << ans << '\n';
}   
