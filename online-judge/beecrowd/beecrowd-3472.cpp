// Up there the piano

/*
cukup simulasi sesuai yang diminta soal.
*/

#include<bits/stdc++.h>
using namespace std;

bool eliminated[5000];

signed main() {
	int n;
	cin >> n;

	const int J = 29, SZ = 2 * n;
	int cur = 0;

	n *= 2;

	while (n > 1) {
		int m = J%n-1;
		if (m < 0) m += n;
		while (m>0) {
			if (!eliminated[cur]) m--;
			cur = (cur + 1) % SZ;
		}
		while(eliminated[cur]) cur = (cur + 1) % SZ;
		eliminated[cur++] = 1;
		n--;
	}

	cout << (!eliminated[0] || !eliminated[1] ? "vai ganhar\n" : "nao vai ganhar\n");
}
