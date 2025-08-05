#include <bits/stdc++.h>
using namespace std;

#ifdef debug
#define trace(x) cerr << #x << ": " << x << '\n'
#else
#define trace(x)
#endif

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<int, int> pre, nxt;
  int front = a[0], end = a[n-1];

  for (int i = 1; i < n; i++) pre[a[i]] = a[i-1];
  for (int i = 0; i + 1 < n; i++) nxt[a[i]] = a[i+1];

  while (k--) {
    char c;
    int x;
    cin >> c >> x;

    if (c == 'G') {
      nxt[end] = front;
      pre[front] = end;
      front = x;
      end = pre[x];
    } else {
      pre[front] = x;
      nxt[x] = front;
      front = x;
      ++n;      
    }
  }

  cout << n << '\n';
  for (int cur = front;; cur = nxt[cur]) {
    cout << cur << ' ';
    if (cur == end) break;
  }
  cout << '\n';
}
