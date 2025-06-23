#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> pref(26, vector<int>(n + 5, 0)), suff(26, vector<int>(n + 5, 0));

    for (int i = 0; i < n; i++) {
      pref[s[i] - 'a'][i + 1]++;
      for (int j = 0; j < 26; j++) {
        pref[j][i + 1] += pref[j][i];
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      suff[s[i] - 'a'][i + 1]++;
      for (int j = 0; j < 26; j++) {
        suff[j][i + 1] += suff[j][i + 2];
      }
    }

    bool found = 0;

    for (int i = 1; i < n - 1; i++) {
      if (pref[s[i] - 'a'][i] > 0 || suff[s[i] - 'a'][i + 2] > 0) {
        found = 1;
        break;
      }
    }

    cout << (found ? "yes" : "no") << '\n';
  }
}
