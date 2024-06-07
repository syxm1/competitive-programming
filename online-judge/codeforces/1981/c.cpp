/**************************
* syxm1
* created: 2024-06-06 20:56 
**************************/

#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;

#define fi first
#define se second

int n;
bool ok;
vector<int> a, b;
vector<pair<int, int>> k;

int msb(int x) {
	return 31 - __builtin_clz(x);
}

bool equal(int x, int y) {
	int tx = x, ty = y;
	if (tx > ty) swap(tx, ty);
	return (ty >> (msb(ty) - msb(tx))) == tx;
}

void solve(int cur, int nxt, int idc, int idn) {
	int tc = cur, tn = nxt;
	if (cur < nxt) {
		int id = idc + 1;
		while (id < idn && !equal(tc, tn)) {
			tc >>= 1;
			b[id++] = tc;
		}
		if (!equal(tc, tn)) {
			ok = 0;
			return;
		}
		while (id < idn && tc != tn) {
			tc <<= 1;
			if ((1 << (msb(tn) - msb(tc))) & tn) tc |= 1;
			b[id++] = tc;
		}
		int p = id, flag = 0;
		if (b[id-1] * 2 > (int) 1e9) flag = 1;
		while (id < idn) {
			if (flag) {
				if ((id & 1) == (p & 1)) tc >>= 1;
				else tc <<= 1;
			} 
			else {
				if ((id &1) == (p & 1)) tc <<= 1;
				else tc >>= 1;
			}

			b[id++] = tc;
		}
		if ((b[idn] >> 1) != b[idn-1] && (b[idn-1] >> 1) != b[idn]) {
			ok = 0;
			return;
		}
	}
	else {
		int id = idn - 1;
		while (id > idc && !equal(tc, tn)) {
			tn >>= 1;
			b[id--] = tn;
		}
		if (!equal(tc, tn)) {
			ok = 0;
			return;
		}
		while (id > idc && tc != tn) {
			tn <<= 1;
			if ((1 << (msb(tc) - msb(tn))) & tc) tn |= 1;
			b[id--] = tn;
		}
		int p = id, flag = 0;
		if (b[id+1] * 2 > (int) 1e9) flag = 1;
		while (id > idc) {
			if (flag) {
				if ((id & 1) == (p & 1)) tn >>= 1;
				else tn <<= 1;
			} 
			else {
				if ((id &1) == (p & 1)) tn <<= 1;
				else tn >>= 1;
			}
			b[id--] = tn;
		}
		if ((b[idc] >> 1) != b[idc+1] && (b[idc+1] >> 1) != b[idc]) {
			ok = 0;
			return;
		}
	}
}

void test_case() {
	ok = 1;
	a.clear();
	b.clear();
	k.clear();
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != -1) {
			b[i] = a[i];
			k.push_back(make_pair(a[i], i));
		}
	}
	if ((int) k.size() == 0) {
		k.push_back(make_pair(1, 0));
		b[0] = 1;
	}
	for (int i = 0; i + 1 < (int) k.size(); i++) {
		if (!ok) break;
		solve(k[i].fi, k[i+1].fi, k[i].se, k[i+1].se);
	}
	bool flag;
	flag = k[0].fi * 2 > (int) 1e9;
	for (int i = k[0].se - 1; i >= 0; i--) {
		if (flag) {
			if (i % 2 == (k[0].se - 1) % 2) b[i] = b[i+1]/2;
			else b[i] = b[i+1]*2;
		}
		else {
			if (i % 2 == (k[0].se - 1) % 2) b[i] = b[i+1]*2;
			else b[i] = b[i+1]/2;
		}
	}
	flag = k.back().fi * 2 > (int) 1e9;
	for (int i = k.back().se + 1; i < n; i++) {
		if (flag) {
			if (i % 2 == (k.back().se + 1) % 2) b[i] = b[i-1]/2;
			else b[i] = b[i-1]*2;
		}
		else {
			if (i % 2 == (k.back().se + 1) % 2) b[i] = b[i-1]*2;
			else b[i] = b[i-1]/2;
		}
	}
	if (!ok) {
		cout << -1 << '\n';
	}
	else {
		for (int x : b) {
			cout << x << ' ';
		}
		cout << '\n';
	}
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
