// Awkward Situation

/*
dp[i] := minimum untuk menyusun s[1], ..., s[i].
dp[i] = min(dp[i], dp[st-1] + 1), dimana st merupakan titik permulaan suatu piece yang berakhir di i.
*/

#include<bits/stdc++.h>
using namespace std;

const string origin = "BSUIROPEN";
const int inf = 1e6;

signed main() {
    int n;
    cin >> n;

    vector<tuple<int, int>> v;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if ((int) s.size() > 9) continue;

        int pos = origin.find(s);
        if (pos < 9 && pos >= 0) {
            v.push_back({pos, pos + (int) s.length() - 1});
        }
    }

    n = (int) v.size();

    vector<int> dp(10, inf);

    dp[0] = 0;

    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < n; j++) {
            auto [st, en] = v[j];
            if (en == i-1) dp[i] = min(dp[i], 1 + dp[st]);
        }
    }

    cout << (dp[9] == inf ? -1 : dp[9]) << '\n';
}
