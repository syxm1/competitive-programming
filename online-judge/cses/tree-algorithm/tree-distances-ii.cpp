// syxm1

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

ll n;
vector<ll> sub, root_dist, ans;
vector<vector<int>> adj;

void get_root_dist(int cur, int pre) {
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            root_dist[nxt] = root_dist[cur] + 1; 
            get_root_dist(nxt, cur);
        }
    }
}

void get_sub(int cur, int pre) {
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            get_sub(nxt, cur);
            sub[cur] += sub[nxt] + 1;
        }
    }
}

void get_ans(int cur, int pre) {
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            ans[nxt] = ans[cur] + n - 2 * sub[nxt] - 2;
            get_ans(nxt, cur);
        }
    }
}

void test_case() 
{
    cin >> n;

    adj.clear();
    adj.resize(n);
    sub.assign(n, 0);
    ans.assign(n, 0);
    root_dist.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    root_dist[0] = 0;
    get_root_dist(0, -1);

    for (int i = 0; i < n; i++) ans[0] += root_dist[i];

    get_sub(0, -1);
    get_ans(0, -1);

    for (ll x : ans) {
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
