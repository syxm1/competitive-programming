#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, k;
    string s;

    cin >> n >> k >> s;

    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++) {
      cnt[s[i] - '0']++;
    }
  }
}
