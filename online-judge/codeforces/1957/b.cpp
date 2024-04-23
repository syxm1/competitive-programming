#include<bits/stdc++.h>
using namespace std;

int log2(int x) {
	int ret = 0;
	while(x>1) x/=2, ret++;
	return ret;
}

int binpow(int a, int x) {
	int ret = 1;
	while (x) {
		if (x & 1) ret *= a;
		a *= a;
		x >>= 1;
	}
	return ret;
}

void tc() {
	int n, k;
	cin >> n >> k;

	if (n == 1) {
		cout << k << '\n';
		return;
	}

	int val = binpow(2, log2(k)) - 1;
	k -= val;

	cout << val << ' ' << k << ' ';

	for (int i = 0; i < n - 2; i++) {
		cout << 0 << ' ';
	}

	cout << '\n';
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
greedy : pick the maximum 2^n - 1 first, and put the remaining.
*/
