// Wolves

/*
binary-search the answer untuk kemungkinan waktu.
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(6);

    ll k, n;

    while (cin >> k >> n) {
        if (k == 0 && n == 0) break;

        vector<db> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (k < n) {
            cout << "Impossible\n";
            continue;
        }

        db lo = 1e-6, hi = 1e15, ans;
        for (int i = 0; i < 100; i++) {
            db md = (lo + hi) / 2.00;

            ll tot = 0;

            for (int i = 0; i < n; i++) {
                tot += ceil(a[i] / md);
            }

            if (tot <= k) {
                ans = md;
                hi = md;
            } else {
                lo = md;
            }
        }

        cout << ans << '\n';
    }
}
