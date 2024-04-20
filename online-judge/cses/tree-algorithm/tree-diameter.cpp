// syxm1
// CSES-1131

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

void dfs(int cur, vector<vector<int>> &adj, vector<int> &dist) 
{
    stack<int> S;
    S.push(cur);
    dist[cur] = 0;
    while (!S.empty()) {
        int curr = S.top();
        S.pop();
        for (int next : adj[curr]) {
            if (dist[curr] + 1 < dist[next]) {
                dist[next] = dist[curr] + 1;
                S.push(next);
            }
        }
    }
}

int diameter(vector<vector<int>> &adj) 
{
    int n = adj.size();
    vector<int> dist(n, 1e9);
    dfs(0, adj, dist);
    int x = max_element(dist.begin(), dist.end()) - dist.begin();
    dist.assign(n, 1e9);
    dfs(x, adj, dist);
    return *max_element(dist.begin(), dist.end());
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

    cout << diameter(adj) << '\n';
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
