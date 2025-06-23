#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int totA = 0, totB = 0, totC = 0, totD = 0;
  vector<int> arr(n), A(n + 5, 0), B(n + 5, 0), C(n + 5, 0), D(n + 5, 0);

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    int costA = arr[i];
    int costB = (arr[i] + 3) % 4;
    int costC = (arr[i] + 2) % 4;
    int costD = (arr[i] + 1) % 4;
    totA += costA;
    totB += costB;
    totC += costC;
    totD += costD;
    A[1] += costA, A[i] -= costA, A[i+1] += costA, A[n+1] -= costA;
    B[1] += costB, B[i] -= costB, B[i+1] += costB, B[n+1] -= costB;
    C[1] += costC, C[i] -= costC, C[i+1] += costC, C[n+1] -= costC;
    D[1] += costD, D[i] -= costD, D[i+1] += costD, D[n+1] -= costD;
  }
  
  int prodA = (arr[1] + A[1]) % 4;
  int prodB = (arr[1] + B[1]) % 4;
  int prodC = (arr[1] + C[1]) % 4;
  int prodD = (arr[1] + D[1]) % 4;

  int ansA = totA + (4 - prodA) % 4;
  int ansB = totB + (4 - prodB) % 4;
  int ansC = totC + (4 - prodC) % 4;
  int ansD = totD + (4 - prodD) % 4;

  cout << min({ansA, ansB, ansC, ansD}) << '\n';
}
