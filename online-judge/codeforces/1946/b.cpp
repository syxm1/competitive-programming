/*
    syxm1

    maximum subarray sum.
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9+7;

ll binpow(ll a, ll x, const int mod) {
    ll ret = 1;

    while(x) {
        if(x & 1)
            ret = ((ret % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        x >>= 1;
    }

    return ret;
}

void MAIN()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n+1, 0), pref(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }

    ll max_subarray = 0;
    pair<ll, int> min_pref = {0, 0};
    int start = 0, end = 0;
    for(int i = 1; i <= n; i++) {
        if(pref[i] - min_pref.first > max_subarray) {
            max_subarray = pref[i] - min_pref.first;
            start = min_pref.second;
            end = i;
        }

        if(pref[i] < min_pref.first) {
            min_pref = {pref[i], i};
        }
    }

    ll ans, cache = 0;

    for(int i = 1; i <= n; i++) {
        if(i <= start || i > end) cache = (cache + a[i]) % mod;
        if(cache < 0) cache += mod;
    }

    max_subarray %= mod;
    // cout << max_subarray << ' ' << cache << endl;
    // cout << start << ' ' << end << endl;

    ans = (((binpow(2, k, mod) * max_subarray) % mod) + cache) % mod;
    if(ans < 0) ans += mod;

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;

    while(tc--) {
        MAIN();
    }

    return 0;
}
