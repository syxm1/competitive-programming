#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a;
  cin >> a;

  cout << (400 % a == 0 ? 400 / a : -1) << '\n';
}
