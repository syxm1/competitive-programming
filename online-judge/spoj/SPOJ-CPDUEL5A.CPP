// Comet Number

/*
coba semua kemungkinan 'E' yang mungkin kemudian cek nilai 'A', 'B', 'C', dan 'D', berdasarkan 'E' sekarang.
*/

#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << ": " << x << '\n';

using ll = long long;

void solve() {
	ll x;
	cin >> x;

	bool ok = 0;

	for (ll E = 1; x >= E * (E + 2) + 1; E++) {
		ll P = E * (x - E * (E + 2) - 1);
		ll Q = E * (E + 2) + 1;

		if (P % Q) continue;

		ll A = P / Q;

		if (A % E) continue;

		ll B = A + 2 * E;
		ll C = A / E + 1;
		ll D = E * (A + E);

		if (A <= 0 || B <= 0 || C <= 0 || D <= 0) continue;

		ok = 1;
		break;
	}

	cout << (ok ? "YES\n" : "NO\n");
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;

	while (tc--) {
		solve();
	}
}
