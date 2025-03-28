#include<bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T> struct fenwick2d {
    vector<vector<T>> fen, arr;
    size_t n, m;

    fenwick2d(size_t x, size_t y) {
    	this->n = x+1;
    	this->m = y+1;
    	fen.assign(n, vector<T>(m, 0));
    	arr.assign(n, vector<T>(m, 0));
    }

    fenwick2d(vector<vector<T>> v) : fenwick2d(v.size(), v[0].size()) {
    	for (size_t i = 0; i < v.size(); i++) {	
    		for (size_t j = 0; j < v[0].size(); j++) {
    			upd(i, j, v[i][j]);
    			arr[i][j] = v[i][j];
    		}
    	}
    }

    T sum(size_t x, size_t y) {
    	x++, y++;
        T ret = 0;
        for (size_t i = x; i > 0; i -= (i & (-i)))
            for (size_t j = y; j > 0; j -= (j & (-j)))
                ret += fen[i][j];
        return ret;
    }

    void add(size_t x, size_t y, T delta) {
    	x++, y++;
        for (size_t i = x; i < n; i += (i & (-i)))
            for (size_t j = y; j < m; j += (j & (-j)))
                fen[i][j] += delta;
    }
	
	void upd(size_t x, size_t y, T val) {
		add(x, y, val - arr[x+1][y+1]);
	}
};

void test_case() {
	vector<vector<int>> v = {{1, 2}, {3, 4}};
	fenwick2d pref(v);
	int x, y;
	cin >> x >> y;
	cout << pref.sum(x, y) << '\n';
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
