// Booby's Amazing Cake

// syxm1

/*
brute-force untuk semua kemungkinan pasangan titik yang menjadi garis bagi, hitung jumlah jarak di kanan dan kiri lalu bandingkan.
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = long double;

const db eps = 1e-6;

struct point {
	db x, y;
};

struct line {
	db a, b, c;

	line(point p, point q) {
		this->a = p.y - q.y;
		this->b = q.x - p.x;
		this->c = p.x * (q.y - p.y) - p.y * (q.x - p.x);
	}
};

db dist(line l, point p) {
	return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

db crossproduct(point p, point q, point r) {
	return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

int n;
vector<point> a;

void test_case() 
{
	while (cin >> n) {
		if (n == 0) break;

		a.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y;
		}

		db ans = 1e9;

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				line l(a[i], a[j]);
				db lf = 0, rg = 0;
				for (int k = 0; k < n; k++) {
					if (k == i || k == j) continue;
					if (crossproduct(a[i], a[j], a[k]) > 0) {
						lf += dist(l, a[k]);
					} else if (crossproduct(a[i], a[j], a[k]) < 0) {
						rg += dist(l, a[k]);
					}
				}
				ans = min(ans, abs(lf - rg));
			}
		}

		cout << ans << '\n';
	}
}

signed main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(3);

	int tc = 1;
	// cin >> tc;

	while (tc--) {
		test_case();
	}
}
