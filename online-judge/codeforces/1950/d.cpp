/*
    syxm1
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

set<int> bin;

void MAIN()
{
    int n;
    cin >> n;

    if(bin.count(n)) {
        cout << "YES\n";
        return;
    }

    for(int x : bin) {
        while(n % x == 0) {
            n /= x;
        }
    }

    cout << (n == 1 ? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int mask = 2; mask < (1 << 5); mask++) {
        int num = 0;
        for(int i = 0; i < 5; i++) {
            if(mask & (1 << i)) {
                num += pow(10, i);
            }
        }
        bin.insert(num);
    }

    // for(int i : bin) cout << i << ' '; cout << '\n';

    int tc = 1;
    cin >> tc;

    while(tc--) {
        MAIN();
    }

    return 0;
}
