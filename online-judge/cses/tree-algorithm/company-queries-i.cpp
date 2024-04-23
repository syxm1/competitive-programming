// syxm1

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
vector<int> lvl;

void dfs(int cur) {
    for (int nxt : adj[cur]) {
        lvl[nxt] = lvl[cur] + 1;
        dfs(nxt);
    }
}

int ancestor(int x, int k) {
    int ret = x;
    for (int i = 0; i < B; i++) {
        if ((k >> i) & 1) ret = up[ret][i];
    }
    return ret;
}

void test_case() 
{
    int n, q;
    cin >> n >> q;

    adj.resize(n);
    lvl.assign(n, 0);
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
        int x, k; cin >> x >> k; --x;
        cout << (lvl[x] < k ? -1 : ancestor(x, k) + 1) << '\n';
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
