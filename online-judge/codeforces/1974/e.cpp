/**************************
* syxm1
* created: 2024-05-23 21:08 
**************************/

/*
* knapsack
*/

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

ll n, x, s;

void test_case() {
    cin >> n >> x;

    vector<ll> c(n+1), h(n+1);
        
    s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> h[i];
        s += h[i];
    }

    vector<ll> dp(s+1, 1e18);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= h[i]; j--) {
            if (x * (i-1) - dp[j-h[i]] >= c[i]) 
                dp[j] = min(dp[j], dp[j-h[i]] + c[i]);
        }
    }

    for (int i = s; i >= 0; i--) {
        if (dp[i] != 1e18) {
            cout << i << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc = 1;
    cin >> tc;

    while (tc--) {
        test_case();
    }
}
