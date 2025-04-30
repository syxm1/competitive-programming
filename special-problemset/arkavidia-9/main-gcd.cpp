#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mxn = 2e5+10;
const int mod = 998244353;

int n, a, ans = 1;

vector<int> spf(mxn, 0);
vector<vector<int>> cnt(mxn);

int binpow(int a, int x) {
  int ret = 1;
  while (x) {
    if (x & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    x >>= 1;
  }
  return ret;
}

void sieve() {
  spf[1] = 1;
  for (int i = 2; i < mxn; i++) {
    if (spf[i] != 0) continue;
    spf[i] = i;
    for (int j = i * i; j < mxn; j += i) {
      spf[j] = i;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a;
    while (a != 1) {
      int fac = spf[a];
      int num = 0;
      while (a % fac == 0) a /= fac, num++;
      cnt[fac].push_back(num);
    }
  }

  for (int i = 2; i < mxn; i++) {
    if ((int) cnt[i].size() == 0) continue;
    sort(cnt[i].begin(), cnt[i].end());
    const int cur_size = cnt[i].size();
    for (int j = 0; j < cur_size; j++) {
      ans = (ans * binpow(i, (cur_size - j - 1) * cnt[i][j])) % mod;
    }
  }

  cout << ans << '\n';
}
