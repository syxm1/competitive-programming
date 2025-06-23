#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    int mx_sum = (n + 1) * n / 2;
    int mn_sum = n;

    if (m < mn_sum || m > mx_sum) {
      cout << -1 << '\n';
      continue;
    }

    int cur_sum = 0, i = n, id = 0, pivot;
    vector<int> tree;

    while (i > 1) {
      if (cur_sum + i >= m) break;
      tree.push_back(i);
      cur_sum += i--, id++;
    }

    tree.push_back(1);
    cur_sum += 1, pivot = id++;

    while (i > 1) {
      tree.push_back(i--);
      cur_sum++, id++;
    }

    int overflow = cur_sum - m;
    if (overflow > 0) {
      int j = pivot - 1;
      int k = pivot + 1;

      --overflow;
      while (overflow > 0 && k + 1 < n) --overflow, k++;
      while (overflow > 0 && j - 1 >= 0) --overflow, j--;

      swap(tree[j], tree[k]);
    }

    cout << tree[0] << '\n';
    for (int i = 0; i + 1 < n; i++) {
      cout << tree[i] << ' ' << tree[i + 1] << '\n';
    }
  }
}

/*
 * 6 5 4 1 3 2
 *
 * 5 4 3 1 2
 *
 * 1 2 3 4 => 4
 * 2 1 3 4 => 5
 * 3 1 2 4 => 6
 * 4 1 2 3 => 7
 * 4 2 1 3 => 8
 * 4 3 1 2 => 9
 * 4 3 2 1 => 10
 *
 * 1 2 3 => 3
 * 2 1 3 => 4
 * 3 1 2 => 5
 * 3 2 1 => 6
 */
