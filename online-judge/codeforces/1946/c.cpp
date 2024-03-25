/*
    syxm1

    the idea is to binary search for 'x'.
    greedy : 
    -    pick any vertex to root.
    -    cut the tree from the leaf and maintain the size of current component.
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, x, y;

vector<vector<int>> adj;

int dfs(int cur, int prev) {
    int sz = 1;
    for(int nxt : adj[cur]) {
        if(nxt != prev) {
            sz += dfs(nxt, cur);
        }
    }
    if(sz >= x && cur != prev) {
        sz = 0;
        y++;
    }
    return sz;
}

void MAIN()
{
    cin >> n >> k; ++k;
    adj.resize(n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    int lo = 1, hi = n, ans = -1;
    while(lo <= hi) {
        x = (lo + hi) >> 1;
        y = 0;

        int rem = dfs(0, 0);

        if(y >= k || (y == k - 1 && rem >= x)) {
            ans = x;
            lo = x + 1;
        } else {
            hi = x - 1;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;

    while(tc--) {
        adj.clear();
        MAIN();
    }

    return 0;
}
