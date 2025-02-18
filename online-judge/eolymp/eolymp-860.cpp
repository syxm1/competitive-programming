// The game of "Date"

/*
definisikan dp[i][j] := 1, jika bulan i tanggal j merupakan winning possition bagi player 1
                        0, jika bulan i tanggal j merupakan losing position bagi player 2
berlangsungnya permainan bergantung kepada langkah pertama yang diambil oleh permain pertama.
apabila setelah langkah pertama bulan & tanggal sekarang merupakan losing position, maka pemain pertama menang.
sehingga didapat transisi dp:
dp[i][j] = !(dp[i+1][j] && dp[i+2][j] && dp[i][j+1] && dp[i][j+2])
*/

#include<cstdio>

const int day[15] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30, 0, 0};

int d, m; 
bool dp[13][32];

signed main() {
    scanf("%d%d", &d, &m);

    for (int i = 12; i >= 1; i--) {
        for (int j = day[i]; j >= 1; j--) {
            if (i == 12 && j == 30) {
                dp[i][j] = 0;
            } else if (i == 12 && j == 29) {
                dp[i][j] = 1;
            } else {
                if (i + 1 <= 12 && day[i+1] >= j)  dp[i][j] |= (!dp[i+1][j]); // next month
                if (i + 2 <= 12 && day[i+2] >= j) dp[i][j] |= (!dp[i+2][j]); // next 2 months
                if (j + 1 <= day[i]) dp[i][j] |= (!dp[i][j+1]); // next day
                if (j + 2 <= day[i]) dp[i][j] |= (!dp[i][j+2]); // next month
            }
        }
    }

    printf("%d\n", (dp[m][d] ? 1 : 2));
}
