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
	string a, b;
	cin >> a >> b;

	int n = (int) a.length();

	bool ok = 0, atas = 0;

	for (int i = 0; i < n; i++) {
		if (!ok) {
			if (a[i] == b[i]) continue;
			else if(a[i] > b[i]) atas = 1, ok = 1;
			else atas = 0, ok = 1;
		} else {
			if (atas) {
				if (a[i] > b[i]) swap(a[i], b[i]);
			} else {
				if (b[i] > a[i]) swap(a[i], b[i]);
			}
		}
	}	

	cout << a << '\n' << b << '\n';
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
