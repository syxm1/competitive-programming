#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    set<int> s;
    int blank = 0;

    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a == -1) blank++;
      else s.insert(a);
    }

    if (s.empty() && blank) {
      cout << "YES\n";
      continue;
    }

    int cur_mex = 0, mx = *prev(s.end()), mn = *s.begin();
    while (s.count(cur_mex)) cur_mex++;

    int need = mx - mn;
    int dist = 0;

    if (cur_mex > mx - mn) {
      cout << "NO\n";
      continue;
    }

    for (int i = cur_mex + 1; i <= need; i++) {
      if (!s.count(i)) dist++;
    }

    cout << (dist <= blank ? "YES\n" : "NO\n");
  }
}
