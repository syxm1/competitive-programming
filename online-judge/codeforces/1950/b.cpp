/*
    syxm1
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

void MAIN()
{
    int n;
    cin >> n;

    vector<vector<char>> v(2 * n, vector<char>(2 * n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i & 1) == (j & 1)) {
                v[2 * i][2 * j] = '#';
                v[2 * i + 1][2 * j] = '#';
                v[2 * i][2 * j + 1] = '#';
                v[2 * i + 1][2 * j + 1] = '#';
            } else {
                v[2 * i][2 * j] = '.';
                v[2 * i + 1][2 * j] = '.';
                v[2 * i][2 * j + 1] = '.';
                v[2 * i + 1][2 * j + 1] = '.';
            }
        }
    }

    for(int i = 0; i < 2 * n; i++) {
        for(int j = 0; j < 2 * n; j++) {
            cout << v[i][j];
        } cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;

    while(tc--) {
        MAIN();
    }

    return 0;
}
