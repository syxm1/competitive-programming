/*
*    syxm1
*/

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

const int mod = 998244353, N = 5005;

void test_case() 
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }

    sort(a.begin(), a.end());

    vector<vector<ll>> dp(N, vector<ll>(N, 0)); // dp[i][j] := number of subsequence with sum 'i' and maximum value 'j'.
    vector<ll> cnt(N, 0); // cnt[x] := number of subsequence with sum 'x'.

    cnt[a[0]]++;
    dp[a[0]][a[0]]++;

    for (int i = 1; i < n; i++) {
        for (int j = 5000; j > a[i]; j--) { // iterate over possible sum.
            dp[j][a[i]] += cnt[j - a[i]];
            dp[j][a[i]] %= mod;
        }
        for (int j = 5000; j > a[i]; j--) {
            cnt[j] += cnt[j - a[i]];
            cnt[j] %= mod;
        }
        dp[a[i]][a[i]]++;
        cnt[a[i]]++;
    }

    ll ans = 0;

    for (int i = 1; i <= 5000; i++) {
        for (int j = 1; j <= i; j++) {
            if (j <= i / 2) {
                ans += ((i + 1) / 2) * dp[i][j];
                ans %= mod;
            } else {
                ans += j * dp[i][j];
                ans %= mod;
            }
        }
    }

    cout << ans << '\n';
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
