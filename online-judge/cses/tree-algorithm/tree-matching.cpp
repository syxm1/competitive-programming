// syxm1
// CSES-1130

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

int n;
vector<vector<int>> adj, dp;

void dfs(int cur, int pre) {
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            dfs(nxt, cur);
            dp[cur][0] += max(dp[nxt][0], dp[nxt][1]); // not pairing cur node with nxt node.
        }
    }
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            dp[cur][1] = max(dp[cur][1], 1 + dp[cur][0] + dp[nxt][0] - max(dp[nxt][0], dp[nxt][1])); // pairing cur node with nxt node.
        } 
    }
}

void test_case() 
{
    cin >> n;
    adj.clear();
    adj.resize(n);
    dp.assign(n, vector<int>(2, 0));

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    cout << max(dp[0][0], dp[0][1]) << '\n';
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
