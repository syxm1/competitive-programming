#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            ans++;
            continue;
        }
        if (u > v) swap(u, v);
        edges.push_back(make_pair(u, v));
    }

    int cur = edges.size();
    
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());

    ans += cur - edges.size();

    cout << ans << '\n';
}
