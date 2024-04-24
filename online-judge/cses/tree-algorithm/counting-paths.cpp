// syxm1

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

const int B = 31;

vector<vector<int>> adj, up;
vector<int> pref, tin, tout;
int timer = 0;

void preprocess(int cur, int pre) {
    tin[cur] = timer++;
    up[cur][0] = pre;
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            preprocess(nxt, cur);
        }
    }
    tout[cur] = timer++;
}

void get_pref(int cur, int pre) {
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            get_pref(nxt, cur);
            pref[cur] += pref[nxt];
        }
    }
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    } 
    else if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = B-1; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void test_case() 
{
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    pref.assign(n, 0);
    up.assign(n, vector<int>(B));

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    preprocess(0, 0);

    for (int j = 1; j < B; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        int l = lca(u, v);
        pref[u]++;
        pref[v]++;
        pref[l]--;
        if (l != up[l][0]) pref[up[l][0]]--;
    }

    get_pref(0, 0);

    for (int x : pref) {
        cout << x << ' ';
    }

    cout << '\n';
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
