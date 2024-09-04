#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 3e5+5, inf = 1e9;

int n, k;
vector<int> a;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        a.push_back(a[i]);
    }

    n *= 2;

    set<int> s;

    int l = 0, r = 0, z = inf;
    s.insert(a[0]);
    while (l < n) {
        while (r + 1 < n) {
            if (s.find(a[r + 1]) != s.end()) break;
            int nmn = min(*s.begin(), a[r+1]);
            int nmx = max(*s.rbegin(), a[r+1]);
            if (nmx - nmn + 1 > k) break;
            s.insert(a[r+1]);
            ++r;
        }
        z = min(z, k - (r - l + 1));
        s.erase(a[l]);
        ++l;
        if (l > r) {
            r = l;
            s.insert(a[l]);
        }
    }

    z = max(z, 0ll);

    cout << z << '\n';
}
