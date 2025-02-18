// Xing Tzen Zu’s Movie Theater
/*
banyak konfigurasi yang mungkin = P(n-2, m) * (2 ^ m).
*/
#include<cstdio>

using ll = long long;

const int mod = 1300031, N = 5001;

ll fac[N], inv[N];

ll binpow(ll a, ll x) {
	ll ret = 1;
	while (x) {
		if (x & 1) ret = (ret * a) % mod;
		a = (a * a) % mod;
		x >>= 1;
	}
	return ret;
}

ll p(ll n, ll r) {
	 return (fac[n] * inv[n - r]) % mod;
}

signed main() {
	fac[0] = 1;
	inv[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = (fac[i-1] * i) % mod;
		inv[i] = binpow(fac[i], mod - 2);
	}

	int t;
	scanf("%d", &t);

	while (t--) {
		ll n, m;
		scanf("%lld%lld", &n, &m);
		printf("%lld\n", (p(n - m, m) * binpow(2, m)) % mod);
	}
}
