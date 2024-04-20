// syxm1

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

void dfs(int cur, vector<int> &dist, vector<vector<int>> &adj) {
    for (int nxt : adj[cur]) {
        if (dist[nxt] > dist[cur] + 1) {
            dist[nxt] = dist[cur] + 1;
            dfs(nxt, dist, adj);
        }
    }
}

void test_case() 
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> d1(n, 1e9), d2(n, 1e9);

    d1[0] = 0;
    dfs(0, d1, adj);

    int x = max_element(d1.begin(), d1.end()) - d1.begin();

    d1.assign(n, 1e9);

    d1[x] = 0;
    dfs(x, d1, adj);

    int y = max_element(d1.begin(), d1.end()) - d1.begin();

    d2[y] = 0;
    dfs(y, d2, adj);

    for (int i = 0; i < n; i++) {
        cout << max(d1[i], d2[i]) << " \n"[i == n-1];
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
