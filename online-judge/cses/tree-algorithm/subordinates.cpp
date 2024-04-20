// syxm1
// CSES-1674

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

vector<vector<int>> adj;
vector<int> sub;

void dfs(int cur) {
    for (int nxt : adj[cur]) {
        dfs(nxt);
        sub[cur] += sub[nxt] + 1;
    }
}

void test_case() 
{
    int n;
    cin >> n;

    adj.clear();
    adj.resize(n);
    sub.assign(n, 0);

    for (int i = 1; i < n; i++) {
        int p; cin >> p; adj[--p].push_back(i);
    }

    dfs(0);

    for (int x : sub) {
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
