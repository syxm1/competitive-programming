#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9+7;

ll binpow (ll a, ll b) {
    ll res = 1;
    while (b) { 
        if (b&1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

signed main () {
    ll a, b;
    cin >> a >> b;
    cout << binpow(a, b) << '\n';
}
