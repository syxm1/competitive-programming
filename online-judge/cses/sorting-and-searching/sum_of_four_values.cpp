// syxm1

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void test_case() 
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, vector<pair<int, int>>> m;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            m[a[i]+a[j]].push_back({i, j});
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (auto [k, l] : m[x-a[i]-a[j]]) {
                if (i != k && i != l && j != k && j != l) {
                    cout << i+1 << ' ' << j+1 << ' ' << k+1 << ' ' << l+1 << '\n';
                    return;
                } 
            }
        }
    }

    cout << "IMPOSSIBLE\n";
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
