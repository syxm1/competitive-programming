// Prizes
// status : partially accepted 15%
/*
menggunakan teknik dp, dengan dp[i][j][k] = banyak t-shirt maksimum yang bisa didistribusikan dari index 'i'
kebelakang, apabila meletakkan sebanyak 'k' pada b[0], dengan sisa dari peletakkan sebelumnya sebanyak 'j'.
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int dp[15][105][105], a[15], b[15], n;

int solve(int id, int rem, int p) {
	if (id == n) {
		return min(rem, b[0] - p);
	} 

	else if (dp[id][rem][p] != -1) {
		return dp[id][rem][p];
	}

	int ret = 0;
	for (int i = 0; i <= min(b[id], a[id] + rem); i++) {
		int next_rem = (i > rem ? a[id] + rem - i : a[id]);
		ret = max(ret, i + solve(id + 1, next_rem, p));
	}
	return dp[id][rem][p] = ret;
}

signed main() {
	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		int ans = 0;

		for (int i = 0; i <= min(b[0], a[0]) ; i++) {
			for (int j = 0; j < 15; j++) {
				for (int k = 0; k < 105; k++) {
					dp[j][k][i] = -1;
				}
			}

			int val = i + solve(1, a[0] - i, i);

			ans = max(ans, val);
		}
		cout << ans << '\n';
	}
}
