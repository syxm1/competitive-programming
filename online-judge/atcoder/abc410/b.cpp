#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> box(n, 0), ans(q);

  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;

    if (x >= 1) {
      box[x - 1]++;
      ans[i] = x;
    }
    else {
      int id = min_element(box.begin(), box.end()) - box.begin();
      box[id]++;
      ans[i] = id + 1;
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << " \n"[i == q - 1];
  }
}
