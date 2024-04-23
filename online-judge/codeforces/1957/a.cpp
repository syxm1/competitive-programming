#include<bits/stdc++.h>
using namespace std;

void tc() {
	int n;
	cin >> n;

	vector<int> cnt(105,0);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	int ans = 0;

	for (int i = 1; i <= 100; i++) {
		ans += cnt[i] / 3;
	} 

	cout << ans << '\n';
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
