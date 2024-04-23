/*
it's unnecessary to maintain rook's position (only need to consider how many numbers of rows and columns left).
dp[n] := number of possible solution for board size n * n.
possible choice:
- putting rook on (r, c) where r != c, equals to removing 2 rows and 2 columns.
- otherwise, r == c, equals to removing 1 rows and 1 columns.
for the first choice, number of possible position for rook is 2 * (i-1).
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9+7, N = 3e5+5;

ll dp[N];

void tc() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		n -= (u == v ? 1 : 2);
	}

	cout << dp[n] << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0] = 1;
	dp[1] = 1;

	for (ll i = 2; i < N; i++) {
		dp[i] = (((((2LL * (i - 1)) % mod) * dp[i - 2]) % mod) + dp[i - 1]) % mod;
	} 

	int t;
	cin >> t;

	while (t--) {
		tc();
	}
}

/* brute force program:
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9+7;

int n, k;

map<tuple<int, vector<bool>, vector<bool>>, ll> dp;

ll solve(int id, vector<bool> col, vector<bool> row) {
	if (id == n) {
		for (int i = 0; i < n; i++) {
			if (!col[i] || !row[i]) return 0;
		}
		return 1;
	}

	if (dp[{id, col, row}] != 0) {
		return dp[{id, col, row}];
	}

	ll ret = solve(id + 1, col, row);

	if (!col[id]) {
		for (int i = 0; i < n; i++) {
			if (!row[i]) {
				vector<bool> roww = row, coll = col;
				roww[i] = coll[i] = roww[id] = coll[id] = 1;
				ret = (ret + solve(id + 1, coll, roww)) % mod;
			}
		}
	}

	return dp[{id, col, row}] = ret;
}

void tc() {
	cin >> n >> k;

	vector<bool> col(n, 0), row(n, 0);

	for (ll i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		col[u] = row[u] = col[v] = row[v] = 1;
	}

	ll ans = solve(0, col, row);

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		tc();
	}
}
*/
