// syxm1

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

int B = 30;

vector<vector<int>> adj, up;
vector<int> tin, tout, dist;
int timer = 0;

void dfs(int cur, int pre) {
    tin[cur] = timer++;
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            up[nxt][0] = cur;
            dist[nxt] = dist[cur] + 1;
            dfs(nxt, cur);
        }
    }
    tout[cur] = timer++;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = B-1; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int d(int u, int v) {
    return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

void test_case() 
{
    int n, q;
    cin >> n >> q; 

    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    dist.resize(n);
    up.assign(n, vector<int>(B));

    for (int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist[0] = 0;
    dfs(0, -1);

    for (int j = 1; j < B; j++) {
        for (int i = 1; i < n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << d(u, v) << '\n';
    }
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;

    while (tc--) {
        test_case();
    }
}
