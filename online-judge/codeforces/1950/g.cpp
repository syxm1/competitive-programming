/*
    syxm1

    represent the song list as a graph with adjacency list.
    do dp bitmask to find the maximum possible playlist length.
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

int n;
vector<pair<string, string>> v;
vector<vector<int>> dp;
vector<vector<int>> adj;

int solve(int cur, int mask) {
    if (dp[cur][mask] != -1) {
        return dp[cur][mask];
    }

    int ret = __builtin_popcount(mask);

    for (int nxt : adj[cur]) {
        if (!(mask & (1 << (nxt - 1)))) {
            ret = max(ret, solve(nxt, mask | (1 << (nxt - 1))));
        }
    }

    return dp[cur][mask] = ret;
}

void init(int m) {
    dp.clear();
    adj.clear();
    dp.assign(m + 1, vector<int> ((1 << m), -1));
    adj.resize(m+1);
    v.resize(m);
}

void MAIN()
{
    cin >> n;

    init(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }


    for (int i = 1; i <= n; i++) {
        adj[0].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (v[i].first == v[j].first || v[i].second == v[j].second) {
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
    }

    cout << n - solve(0, 0) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;

    while(tc--) {
        MAIN();
    }

    return 0;
}
