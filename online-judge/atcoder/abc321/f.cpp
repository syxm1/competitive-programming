#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, k;
    cin >> q >> k;

    vector<int> dp(k+1, 0);

    dp[0] = 1;
    while (q--) {
        char c; int x;
        cin >> c >> x;

        if (c == '+') {
            // dp jalan dari belakang karena tiap elemen cuma bisa diambil sekali
            for (int i = k; i >= x; i--) {
                dp[i] = (dp[i] + dp[i-x]) % mod;
            }
        }
        else {
            // dp jalan dari depan karena inverse dari operasi '+'
            for (int i = x; i <= k; i++) {
                dp[i] = (dp[i] - dp[i-x]) % mod;
                if (dp[i] < 0) dp[i] = (dp[i] + mod) % mod;
            }
        }

        cout << dp[k] << '\n';
    }
}


/*
 * 1, 2, 3   x = 5
 * 
 * 0 1 2 3 4 5 
 * 1 1 2 4 7 13
 *
 * removes 2
 * 1 1 1 2 3 4
*/
