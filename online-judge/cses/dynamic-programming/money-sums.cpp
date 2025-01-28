#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }


    vector<bool> pos(1e5+5, 0);

    pos[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1e5; j >= x[i]; j--) {
            if (pos[j - x[i]]) pos[j] = 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 1e5; i++) {
        ans += pos[i];
    }

    cout << ans << '\n';
    for (int i = 1; i <= 1e5; i++) {
        if (pos[i]) cout << i << ' ';
    }
    cout << '\n';
}
