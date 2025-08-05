/**************************
* syxm1
* created: 2024-05-19 09:55 
* link: https://tlx.toki.id/problems/findit-2024-cp-penyisihan/B
**************************/

/*
 *	f[n][0] = f[n-1][2] + f[n-1][0]
 *	f[n][1] = f[n-1][2] + f[n-1][1]
 *	f[n][2] = 3 * f[n-1][2] + f[n-1][1] + f[n-1][0]
 *
 *	ans = {f[i][0], f[i][1], f[i][2]}
 *
 * 	transition:
 *	{
 *	{1, 0, 1},
 *	{0, 1, 1},
 *	{1, 1, 3},
 *	}
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9+7;

const vector<vector<ll>> base = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
vector<vector<ll>> trans = {{1, 0, 1}, {0, 1, 1}, {1, 1, 3}}, ans = {{0, 0, 1}};

ll n;

vector<vector<ll>> mul(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
	vector<vector<ll>> c(a.size(), vector<ll>(b[0].size()));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) {
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
			}
		}
	}
	return c;
}

vector<vector<ll>> expmod(vector<vector<ll>> &a, ll x) {
	vector<vector<ll>> ret = base;
	while (x) {
		if (x & 1) {
			ret = mul(ret, a);
		}
		a = mul(a, a);
		x >>= 1;
	}
	return ret;
}

void test_case() {
	cin >> n;

	if (n & 1) {
		cout << 0 << '\n';
		return;
	}

	n /= 2;
	
	ans = mul(ans, expmod(trans, n));

	cout << ans[0][2] << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc = 1;
	// cin >> tc;

	while (tc--) {
		test_case();
	}
}
