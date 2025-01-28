#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
 * dp[x] = minimum price to pay for 'x' pages
 * flying table optimization
 */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> h(n+5), s(n+5);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> s[i];

    vector<int> dp(x+5, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }

    cout << dp[x] << '\n';
}
