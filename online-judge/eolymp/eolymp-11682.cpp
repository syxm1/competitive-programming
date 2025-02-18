// Special Deal
/*
greedy: ambil mulai dari 3 elemen terbesar dst.
*/
#include<cstdio>
#include<algorithm>

using ll = long long;

const int N = 1e5;
int n, a[N];
ll ans;

signed main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}		

	std::sort(a, a+n);

	for (int i = n-1; i >= 0; i -= 3) {
		if (i >= 1) ans += (a[i] + a[i-1]);
		else ans += a[i];
	}

	printf("%lld", ans);
}	
