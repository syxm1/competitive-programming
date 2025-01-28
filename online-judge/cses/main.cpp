#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> dp(x+1, 0);

    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0) dp[i] = (dp[i] + dp[i - c[j]]) % mod;
        }
    }

    cout << dp[x] << '\n';
}
