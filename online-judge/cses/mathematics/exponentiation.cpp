#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

int binpow(int a, int x) {
  int ret = 1;
  while (x) {
    if (x & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    x >>= 1;
  }
  return ret;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << binpow(a, b) << '\n';
  }
  
}
