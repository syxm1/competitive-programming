// syxm1

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, q;
vector<int> a;

void test_case() 
{
    cin >> n >> q;

    a.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (a[r] ^ a[l-1]) << '\n';
    }
}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;

    while (tc--) {
        test_case();
    }
}
