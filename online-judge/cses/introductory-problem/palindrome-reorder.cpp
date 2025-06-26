#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  vector<int> cnt(26, 0);
  for (int i = 0; i < (int) s.length(); i++) {
    cnt[s[i] - 'A']++;
  }

  int odd_cnt = 0, odd_id;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] & 1) {
      odd_cnt++;
      odd_id = i;
    }
  }

  if (odd_cnt > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }

  string ans = "";
  
  for (int i = 0; i < 26; i++) {
    if (i == odd_id) continue;
    for (int j = 0; j < cnt[i] / 2; j++) {
      ans.push_back((char) 'A' + i);
    }
  }
  
  if (odd_cnt == 1) {
    for (int j = 0; j < cnt[odd_id]; j++) {
      ans.push_back((char) 'A' + odd_id);
    }
  }

  for (int i = 25; i >= 0; i--) {
    if (i == odd_id) continue;
    for (int j = 0; j < cnt[i] / 2; j++) {
      ans.push_back((char) 'A' + i);
    }
  }

  cout << ans << '\n';
}
