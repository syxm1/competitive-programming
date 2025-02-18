// Balls and Queries

/*
maintain jumlah pasangan (x, y) yang sama.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5+5;

int n, q, que, i, k, sum, cnt[N];
vector<int> a;

int f(int x) {
    return x * (x - 1LL) / 2LL;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (auto q : cnt) {
        sum += f(q);
    }

    while (q--) {
        cin >> que;

        if (que == 1) {
            cin >> i >> k;
            --i;
            sum -= f(cnt[a[i]]);
            sum += f(cnt[a[i]] - 1);
            cnt[a[i]]--;
            sum -= f(cnt[k]);
            sum += f(cnt[k] + 1);
            cnt[k]++;
            a[i] = k;
        }

        else {
            cin >> i;
            --i;
            cout << sum - f(cnt[a[i]]) + f(cnt[a[i]] - 1LL) << '\n'; 
        }
    }
}
