// Create an Array

/*
observasi : 
untuk mengubah b[l], ..., b[r], dengan a[l] == a[r] dan a[i] != a[l] untuk l+1 <= i <= r-1:
	- diperlukan 1 kali operasi jika a[l] merupakan yang paling minimum pada range (l,r)
 	- diperlukan 2 kali operasi jika a[i] bukan merupakan yang paling minimum pada range (l, r)

sehingga, untuk setiap elemen 'x' pada array 'a', cukup cek apakah diantara tiap2 kemunculan 'x', 
'x' merupakan yang paling minimum.

minimum range static query dapat diselesaikan dengan sparse table.
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5, B = 20;

int n;
vector<int> a, lg(N);
vector<vector<int>> mn;
map<int, vector<int>> id;

void preprocess() {
	for (int i = 0; i < n; i++) {
		mn[i][0] = a[i];
	}
	for (int j = 1; j < B; j++) {
		for (int i = 0; i + (1 << j) <= n; i++) {
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int get_min(int l, int r) {
	int i = lg[r - l + 1];
	return min(mn[l][i], mn[r - (1 << i) + 1][i]);
}

signed main() {
	lg[0] = -1e9;
	lg[1] = 0;

	for (int i = 2; i < N; i++) {
		lg[i] = lg[i / 2] + 1;
	}

	cin >> n;
	a.resize(n);
	mn.resize(n, vector<int>(B));

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != 0) id[a[i]].push_back(i);
	}

	preprocess();

	vector<tuple<int, int, int>> ans;

	for (auto [x, v] : id) {
		int l = v[0], r = v[0];
		for (int i = 1; i <= (int) v.size(); i++) {
			if (i == (int) v.size()) {
				ans.push_back({l, r, x});
			}
			else {
				if (get_min(l, v[i]) != x) {
					ans.push_back({l, r, x});
					l = v[i];
				} 
				r = v[i];
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto [a,b,c] : ans) {
		cout << a+1 << ' ' << b+1 << ' ' << c << '\n';
	}
}
