#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 1e5+5;

int n, sum, w[mxn], d[mxn], dp[mxn][2];
vector<int> adj[mxn];

// dp[i][j] = minimum sum of 0 from i's subtree with i choose to j

void dfs(int cur, int pre) {
    vector<pair<int, int>> aux;
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            dfs(nxt, cur);
            aux.push_back(make_pair(dp[nxt][0], dp[nxt][1]));
        }
    }
    sort(aux.begin(), aux.end(), [&] (pair<int, int> &a, pair<int, int> &b) {
        return a.first - a.second > b.first - b.second;
    });
    for (int i = 0; i < (int) aux.size(); i++) {
        if (i < d[cur]) dp[cur][1] += aux[i].first;
        else dp[cur][0] += aux[i].second;
    }
    dp[cur][0] += w[cur];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        --p;
        adj[p].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    dfs(0, -1);

    int c1 = sum - 2 * dp[0][0];
    int c2 = sum - 2 * dp[0][1];

    cout << max(c1, c2) << '\n';;
}
