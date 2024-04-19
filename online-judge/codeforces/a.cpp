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
	int n, m, k;
	cin >> n >> m >> k;

	cout << (k >= n - (n / m + (n % m != 0)) ? "NO\n" : "YES\n");
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
