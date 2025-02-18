// Get 2024

/*
definisikan:
- dp[i][j] sebagai banyak cara menyusun substring dengan s[i] menjadi digit ke 'j' dari "2024"
- suff[i][j] sebagai suffix-sum dari dp[k][j], i <= k < n;

sehingga transisi dp adalah:
- dp[i][j] = suff[i+1][j+1], jika s[i] bisa ditempatkan di posisi 'j' sebagai penyusun '2024'.
		   = 0, jika sebaliknya.
- suff[i][j] = suff[i+1][j] + dp[i][j].

sehingga jawaban akhir adalah suff[0][0].
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string s = "";
	for (int i = 1; i <= n; i++) {
		int x = i;
		string add = "";
		while(x) {
			add.push_back((x % 10) + '0');
			x /= 10;
		}
		reverse(add.begin(), add.end());
		s += add;
	}

	n = (int) s.length();

	vector<vector<ll>> dp(n, vector<ll>(4, 0)), suff(n, vector<ll>(4, 0));

	dp[n-1][3] = (s[n-1] == '4'); 
	suff[n-1][3] = dp[n-1][3];

	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j <= 3; j++) 
			suff[i][j] = suff[i+1][j];
		
		if (s[i] == '2') {
			dp[i][0] = suff[i+1][1];
			dp[i][2] = suff[i+1][3];
			suff[i][0] = suff[i+1][0] + dp[i][0];
			suff[i][2] = suff[i+1][2] + dp[i][2];
		} else if (s[i] == '0') {
			dp[i][1] = suff[i+1][2];
			suff[i][1] = suff[i+1][1] + dp[i][1];
		} else if (s[i] == '4') {
			suff[i][3] = suff[i+1][3] + 1;
		} 
	}

	cout << suff[0][0] << '\n';
}
