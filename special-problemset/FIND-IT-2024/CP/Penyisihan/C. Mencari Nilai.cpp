/**************************
* syxm1
* created: 2024-05-23 13:06 
**************************/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void test_case() {
    ll n, r, k;
    cin >> n >> r >> k;
    
    vector<ll> a(n);
    for (ll & x : a) {
        cin >> x;
    }

    ll tot = 0;

    for (ll x : a) {
        int i;
        cin >> i;

        tot += x/100LL * i;
    }

    cout << (tot >= r ? "PASS\n" : "NOT PASS\n");
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc = 1;
    // cin >> tc;

    while (tc--) {
        test_case();
    }
}
