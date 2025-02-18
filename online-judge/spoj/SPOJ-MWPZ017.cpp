#include<bits/stdc++.h>
using namespace std;

void tc() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> dp;

	for (int i = 0; i < n; i++) {
		if (dp.size() == 0) {
			dp.push_back(a[i]);
		} else {
			int id = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
			if (id >= (int) dp.size()) {
				dp.push_back(a[i]);
			} else {
				dp[id] = a[i];
			}
		}
	}

	cout << n - (int) dp.size() << '\n';
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

/*
cara terbaik adalah dengan memindahkan elemen yang bukan merupakan anggota dari 'longest-increasing subsequence' yang belum terurut.
sehingga banyak elemen yang perlu dipindahkan adalah n - lis(n), dengan lis(x) merupakan longest-increasing subsequence dari elemen pertama hingga elemen ke 'x'.
*/
