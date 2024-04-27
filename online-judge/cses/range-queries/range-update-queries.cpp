// syxm1

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

#define ls(x) (x & (-x))

using ll = long long;

const int N = 2e5+1;

int n, q;
vector<ll> a(N, 0), fen(N, 0);

void upd(int i, int u) {
    for (; i <= n; i+=ls(i)) {
        fen[i] += u;
    } 
}

ll get(int i) {
    ll ret = 0;
    for (; i > 0; i-=ls(i)) {
        ret += fen[i];
    } 
    return ret;
}

void test_case() 
{
    cin >> n >> q;

    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            upd(a, u);
            upd(b+1, -u);
        }

        else {
            int k;
            cin >> k;
            cout << a[k] + get(k) << '\n';
        }
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
