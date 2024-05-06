// https://oj.uz/problem/view/NOI18_knapsack

/*
- reduce the input by picking s / w for each 1 <= w <= S.
- do the classic knapsack dp.
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define fi first
#define se second

const int S = 2000;

ll s, n, v, w, k, id, cap;
vector<vector<ll>> dp;
vector<pair<ll, ll>> arr;
vector<vector<pair<ll,ll>>> a;

signed main() {
	cin >> s >> n;

	a.resize(S+5);

	for (int i = 0; i < n; i++) {
		cin >> v >> w >> k;
		a[w].push_back({v, k});
	}

	for (int i = 1; i < S; i++) {
		sort(a[i].rbegin(), a[i].rend());
		cap = S / i, id = 0;
		while (cap > 0 && id < (int) a[i].size()) {
			for (int j = 0; j < min(cap, a[i][id].se); j++) {
				arr.push_back({i, a[i][id].fi});
			}
			cap -= min(cap, a[i][id].se), id++;
		}
	}

	dp.assign((int) arr.size(), vector<ll>(s+5));

	for (int i = 0; i <= s; i++) {
		if (i >= arr[0].fi) dp[0][i] = arr[0].se;
	}

	for (int i = 1; i < (int) arr.size(); i++) {
		for (int j = 0; j <= s; j++) {
			dp[i][j] = dp[i-1][j];
			if (j >= arr[i].fi) dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i].fi] + arr[i].se);
		}
	}

	ll ans = 0;

	for (int i = 0; i <= s; i++) {
		ans = max(ans, dp[arr.size()-1][i]);
	}

	cout << ans << '\n';
}
