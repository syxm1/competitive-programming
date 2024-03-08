/*
        syxm1

        CSES - Hamiltonian Flights
        link: https://cses.fi/problemset/task/1690/

        - represent visited city with 'mask'
        - dp[i][mask] is the number of routes to travel from city 1 to city 'i' with 'mask' visited city.
*/

#include<bits/stdc++.h>
using namespace std;
 
// #define int long long
#define pb push_back
#define mod 1000000007
        
int n, m;
vector<vector<int>> adj, dp;
 
signed main() {
        cin >> n >> m;
        
        adj.resize(n);
        dp.assign(n, vector<int>(1 << n, 0));
 
        for(int i = 0; i < m; i++) {
                int u, v;
                cin >> u >> v;
                u--, v--;
 
                adj[v].pb(u);
        }
 
        dp[0][1] = 1;
 
        for(int mask = 2; mask < (1 << n); mask++) {
                if(!(mask & 1)) continue;
                if((mask & 1 << (n-1)) && !(mask & (1 << n) - 1)) continue;
 
                for(int i = 0; i < n; i++) {
                        if(!(mask & (1 << i))) continue;
 
                        int prev = mask ^ (1 << i);
                        for(int j : adj[i]) {
                                if(mask & (1 << j)) {
                                        dp[i][mask] += dp[j][prev];
                                        dp[i][mask] %= mod;
                                }
                        }
                }
        }
 
        cout << dp[n-1][(1<<n)-1];
}
