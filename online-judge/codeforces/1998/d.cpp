#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define trace(x) cerr << #x << ": " << x << endl;
#else
#define trace(x) 37
#endif

#define int long long

/*
- definisikan 'dist[v]' adalah jarak minimum untuk ke 'v' dari '0'
  dengan/tanpa melewati alternative bridges.
- consider index sekarang 'i', apabila ada index 'j' > 'i' dengan
  'j - i' > dist[j] <=> i < j - dist[j], maka ans[i] = 0. sebaliknya ans[i] = 1.
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[v].push_back(u);
        }

        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] + 1;
            for (int j : adj[i]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        multiset<int> alt;
        vector<vector<int>> el(n);
        vector<int> ans(n-1, 0);

        for (int i = n-1; i >= 0; i--) {
            for (int e : el[i]) {
                alt.erase(alt.find(e));
            }
            int mx = alt.empty() ? -1e9 : *(alt.rbegin());
            if (i >= mx && i < n-1) ans[i] = 1;
            for (int j : adj[i]) {
                alt.insert(i - dp[j] - 1);
                el[j].push_back(i - dp[j] - 1);
            }
        }


        for (int i = 0; i < n-1; i++) {
            cout << ans[i];
        }
        cout << '\n';
    }
}
