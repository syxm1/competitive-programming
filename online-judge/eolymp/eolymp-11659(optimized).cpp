// Get 2024 (optimized)
/*
perbandingan dengan kode sebelumnya:
- tidak perlu membentuk string dari input, cukup langsung iterasi dari belakang.
- perubahan definisi dp, dp[i] adalah banyaknya kemungkinan posisi 'i' pada "2024" dari digit terakhir hingga digit sekarang.
- membuang state pertama pada dp[i][j], karena index yang dibutuhkan untuk mencari dp[i][j] hanyalah dp[i+1][j] sehingga state pertama dapat dihilangkan.
*/
#include<cstdio>

using ll = long long;

ll dp[4];

signed main() {
	int n;
	scanf("%d", &n);

	for (int i = n; i >= 1; i--) {
		int x = i;
		while (x) {
			int cur = x % 10;
			if (cur == 2) {
				dp[0] += dp[1];
				dp[2] += dp[3];
			} else if (cur == 0) {
				dp[1] += dp[2];
			} else if (cur == 4) {
				dp[3] += 1LL;
			}
			x /= 10;
		}
	}

	printf("%lld", dp[0]);
}
