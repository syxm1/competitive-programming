/*
*	syxm1
*/

#include<bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

void test_case() 
{
	int n;
	cin >> n;

	bool sama = 1;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != a[0]) sama = 0;
	}

	if (sama) {
		cout << -1 << '\n';
		return;
	}

	vector<int> pref(n, 0);
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i-1] + (a[i] != a[i-1]);
	}

	// trace(pref);

	bool found = 0;
	int ans = 1e9;

	for (int i = 1; i + 1 < n; i++) {
		if (a[i - 1] == a[i + 1] && a[i] != a[i - 1]) {
			found = 1;

			int tol = (upper_bound(pref.begin(), pref.end(), pref[i - 1] - 1) - pref.begin()) - 1;
			int tor = (lower_bound(pref.begin(), pref.end(), pref[i + 1] + 1) - pref.begin());

			// trace(tol, tor);

			int p = i - tol - 1;
			int q = tor - i - 1;

			trace(p, q);

			ans = min({ans, p, q});
		}
	}

	// trace(found);
	cout << (found ? ans : 0) << '\n';
}

signed main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc = 1;
	cin >> tc;

	while (tc--) {
		test_case();
	}
}
