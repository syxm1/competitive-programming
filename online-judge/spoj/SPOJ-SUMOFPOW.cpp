#include<cstdio>
using namespace std;

using ll = long long;

void test_case() {
	ll n, x, y;
	scanf("%lld%lld%lld", &x, &y, &n);
	
	ll ans[n+1];

	ans[0] = 2LL;
	ans[1] = x;

	for (int i = 2; i <= n; i++) {
		ans[i] = ans[i-1] * x - ans[i-2] * y;
	}

	printf("%lld\n", ans[n]);
}

signed main() {
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		test_case();
	}
}

/*
definisikan ans[n] := (p^n) + (q^n), x = p+q, y = pq.
(p^(n-1) + q^(n-1)) * (p + q) = (p^n) + (q^n) + p^(n-1) * q + p * q^(n-1)
				(p^n) + (q^n) = (p^(n-1) + q^(n-1)) * (p + q) - (p^(n-1) * q + p * q^(n-1))
                (p^n) + (q^n) = (p^(n-1) + q^(n-1)) * (p + q) - (p^(n-2) + q^(n-2)) * pq
sehingga diperoleh recurrence relation : ans[n] = ans[n-1] * x - ans[n-2] * y,
dengan base case:
ans[0] = p^0 + q^0 = 1 + 1 = 2
ans[1] = p + q = x
*/
