// Robots Formation

/*
coba semua kemungkinan banyak baris yang mungkin.
jika baris ganjil, maka harus terdapat setidaknya sejumlah banyak 'nilai input yang ganjil' kolom.
jika baris genap, maka tidak boleh ada 'nilai input' yang ganjil.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int tc) {
	int n;
	cin >> n;

	int odd = 0, sum = 0;

	for (int i = 0; i < n; i++) {
		int x; cin >> x; sum += x;
		if (x & 1) odd++;
	}
		
	bool ok = 0;

	for (int i = 2; i <= sum; i++) {
		if (sum % i == 0) {
			int row = i, col = sum / i;
			if (row & 1) {
				if (odd <= col) {
					ok = 1;
					break;
				}
			}
			if (!odd) {
				ok = 1;
				break;
			}
		}
	}

	cout << "Caso #" << tc << ": " << (ok ? "Challenge Accepted!\n" : "Run for your life!\n");
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}
