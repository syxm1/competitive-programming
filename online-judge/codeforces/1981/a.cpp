/**************************
* syxm1
* created: 2024-06-04 13:04 
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
	int l, r;
	cin >> l >> r;
	int ans = 0, x = 1;
	while ((x << 1) <= r) {
		x <<= 1, ans++;
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc = 1;
	cin >> tc;

	while (tc--) {
		test_case();
	}
}
