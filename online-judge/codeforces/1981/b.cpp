/**************************
* syxm1
* created: 2024-06-05 20:03 
**************************/

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

void test_case() {
	ll n, m;
	cin >> n >> m;

	ll ans = 0;

	for (int i = 0; i < 32; i++) {
		ll cur = (1ll << i);
		for (int j = 31; j >= 0; j--) {
			if ((cur | (1ll << j)) <= n + m) {
				cur |= (1ll << j);
			}
		}
		if (cur >= max(0ll, n-m) && cur <= n+m) {
			ans |= (1ll << i);
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll tc = 1;
	cin >> tc;

	while (tc--) {
		test_case();
	}
}
