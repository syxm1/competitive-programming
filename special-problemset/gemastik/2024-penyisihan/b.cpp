#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

const int mxn = 1e5+5;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, l;
  cin >> n >> l;

  vector<int> ans = {l};

  while (n--) {
    int x;
    cin >> x;
    --x;

    ans[x] /= 2;
    ans.insert(ans.begin() + x, ans[x]);
  }

  for (int a : ans) {
    cout << a << ' ';
  }
  cout << '\n';
}
