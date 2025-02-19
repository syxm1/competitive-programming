#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int ans = 0;

    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] != 'B') continue;
        for (int d = 1; i - d >= 0 && i + d < s.length(); d++) {
            int j = i - d, k = i + d;
            if (s[j] == 'A' && s[k] == 'C') ans++;
        }
    }

    cout << ans << '\n';
}
