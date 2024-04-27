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
    int n, q;
    cin >> n >> q;
 
    vector<ll> pref(n+1, 0);
 
    for (int i = 1; i <= n; i++) {
        cin >> pref[i];
        pref[i] = pref[i-1] + pref[i];
    }
 
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << '\n';
    }
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
