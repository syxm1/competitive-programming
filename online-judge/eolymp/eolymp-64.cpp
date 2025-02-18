// The Timetable from "Diez-Product"

/*
lakukan BSTA(Binary Search The Answer) untuk menentukan waktu minimum yg mungkin sehingga K kelas diadakan.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
vector<int> u, c, t;

int cnt(int d) {
	int ret = 0, cycle;
	for (int i = 0; i < n; i++) {
		cycle = u[i] * c[i] + t[i];
		ret += d / cycle * c[i];
		ret += min((d % cycle) / u[i], c[i]);
	}
	return ret;
}

signed main() {
	cin >> n >> k;

	u.resize(n);
	c.resize(n);
	t.resize(n);

	for (int i = 0; i <n; i++) {
		cin >> u[i] >> c[i] >> t[i];
	}

	int lo = 1, hi = 1e6, ans = 1e6;
	while (lo <= hi) {
		int md = (lo + hi) >> 1;
		if (cnt(md) >= k) {
			ans = md;
			hi = md - 1;
		} else {
			lo = md + 1;
		}
	}

	cout << ans << '\n';
}
