// Amin's Research
/*
brute-force untuk semua kemungkinan string patokan.
*/
#include<bits/stdc++.h>
using namespace std;

signed main() {
	int n;
	cin >> n;

	string a[n], b[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i] + a[i];
	}

	int ans = 2e9;

	for (int i = 0; i < n; i++) {
		bool ok = 1;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			bool found = 0;
			int k;
			for (k = 0; k < (int) a[j].length(); k++) {
				if (b[j].substr(k, (int) a[j].length()) == a[i]) {
					found = 1;
					break;
				}
			}
			if (found) {
				cnt += k;
			} else {
				ok = 0;
				break;
			}
		}
		if (ok) {
			ans = min(ans, cnt);
		} else {
			ans = 2e9;
			break;
		} 
	}

	cout << (ans == 2e9 ? -1 : ans) << '\n';
}
