#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mxn = 505;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  vector<int> f(mxn);
  f[0] = 1;
  f[1] = 1;

  for (int i = 2; i < mxn; i++) {
    f[i] = f[i-2] + i - 1;
  }

  while (tc--) {
    int n;
    cin >> n;

    cout << f[n] << '\n';

    // vector<int> a(n);
    // iota(a.begin(), a.end(), 0);

    // set<int> cnt;
    // do {
    //   int sum = 0;
    //   for (int i = 0; i < n; i++) {
    //     cout << a[i] << ' ';
    //     sum += abs(a[i] - i);
    //   }
    //   cout << "- " << sum << '\n';
    //   cnt.insert(sum);
    // } while (next_permutation(a.begin(), a.end()));
    // cout << cnt.size() << '\n';
  }
}
