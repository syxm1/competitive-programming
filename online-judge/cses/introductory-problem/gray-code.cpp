#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        int num = i ^ (i >> 1);
        for (int j = n - 1; j >= 0; j--) {
            cout << ((num >> j) & 1);
        }
        cout << '\n';
    }
}
