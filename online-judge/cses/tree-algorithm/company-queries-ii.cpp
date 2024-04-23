// syxm1

// https://cp-algorithms.com/graph/lca_binary_lifting.html

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

const int B = 30;

vector<vector<int>> adj, up;
vector<int> tin, tout;
int timer = 0;

void dfs(int cur) {
    tin[cur] = timer++;
    for (int nxt : adj[cur]) {
        dfs(nxt);
    }
    tout[cur] = timer++;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    else if(is_ancestor(v, u)) {
        return v;
    }
    for (int i = B-1; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void test_case() 
{
    int n, q;
    cin >> n >> q;

    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    up.assign(n, vector<int>(B));

    for (int i = 1; i < n; i++) {
        int x; cin >> x; --x;
        adj[x].push_back(i);
        up[i][0] = x; 
    }

    for (int j = 1; j < B; j++) {
        for (int i = 1; i < n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    dfs(0);

    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << lca(u, v) + 1 << '\n';
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
