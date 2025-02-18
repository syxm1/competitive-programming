// Superhero

/*
fn = (x+1) * ((y + 1) ^ n) - 1;
*/

#include<cstdio>

using ll = long long;

const int mod = 1e7+9;

ll binpow(ll a, ll x) {
    ll ret = 1;
    while (x) {
        if (x & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        x >>= 1;
    }
    return ret;
}

signed main() {
    int n;
    scanf("%d", &n);

    ll x = 0;
    ll a[n], b[n];

    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
    for (int i = 0; i < n; i++) {
        x = ((x + 1) * binpow(a[i] + 1, b[i])) % mod - 1;
        if (x < 0) x += mod;
    }

    printf("%lld\n", x);    
}
