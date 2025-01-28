#include<bits/stdc++.h>
#define int long long
using namespace std;
 
const int mod = 1e9+7;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    int tar = n * (n + 1) / 2;
    if (tar % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    tar /= 2;
 
    vector<int> dp(tar+5, 0);
 
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = tar; j >= i; j--) {
            dp[j] = (dp[j] + dp[j-i]) % mod;
        }
    }
 
    cout << (dp[tar] * 500000004) % mod << '\n';
}
