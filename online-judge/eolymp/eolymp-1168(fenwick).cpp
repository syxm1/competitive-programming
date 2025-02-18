// Create an Array (fenwick tree approach)
/*
kurang lebih sama dengan cara menggunakan sparse table, hanya beda pada cara penentuan apakah di suatu range (l, r) sudah pernah ditaruh bilangan sebelumnya.
*/
#include<bits/stdc++.h>
using namespace std;

#define lso(x) (x&(-x))

const int N = 1e5+5;

int n, a[N], fen[N];

void add(int i, int d) {
	for (; i <= n; i+=lso(i)) {
		fen[i] += d;
	}
}

int get(int i) {
	int ret = 0;
	for (; i > 0; i-=lso(i)) {
		ret += fen[i];
	}
	return ret;
}

signed main() {
	map<int, vector<int>> id;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 0) id[a[i]].push_back(i);
		else add(i, 1);
	}

	vector<tuple<int, int, int>> ans;

	for (auto [x, v] : id) {
		int l = 0;
		for (int r = 0; r < (int) v.size(); r++) {
			if (r + 1 == (int) v.size() || get(v[r + 1]) - get(v[r]) >= 1) {
				ans.push_back({v[l], v[r], x});
				l = r + 1;
			}
		}
		for (int y : v) add(y, 1);
	} 

	cout << ans.size() << '\n';
	for (auto [a, b, c] : ans) 
		cout << a << ' ' << b << ' ' << c << '\n';
}
