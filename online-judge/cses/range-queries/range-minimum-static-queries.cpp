// syxm1

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "local/debug.h"
#else 
#define trace(...) 37
#endif

using ll = long long;
const int N = 2e5+5, B = 25;

int n, q;
vector<int> a, lg(N);
vector<vector<int>> mn;

int get_min(int l, int r) {
    int i = lg[r - l + 1];
    return min(mn[l][i], mn[r - (1 << i) + 1][i]);
}

void test_case() 
{
    cin >> n >> q;

    a.resize(n);
    mn.resize(n, vector<int>(B));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn[i][0] = a[i];
    }

    for (int j = 1; j < B; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << get_min(a, b) << '\n';
    }
}

signed main() 
{    
    lg[1] = 0;

    for (int i = 2; i < N; i++) {
        lg[i] = lg[i/2] + 1;
    }

    int tc = 1;
    // cin >> tc;

    while (tc--) {
        test_case();
    }
}
