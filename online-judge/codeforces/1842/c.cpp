// syxm1

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

void test_case() 
{
    int n;
    cin >> n;

    vector<int> a(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> mx(n+1, -1), dp(n+1, 0);

    mx[a[1]] = 1;

    for (int i = 2; i <= n; i++) {
        if (mx[a[i]] == -1) {
            dp[i] = dp[i-1];
            mx[a[i]] = i;
        } else {
            dp[i] = max(dp[i-1], dp[mx[a[i]]-1] + i - mx[a[i]] + 1);
            if (dp[i-1] - (i-mx[a[i]]) > dp[mx[a[i]]-1]) {
                mx[a[i]] = i;
            }
        }
    }

    cout << dp[n] << '\n';
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;

    while (tc--) {
        test_case();
    }
}
