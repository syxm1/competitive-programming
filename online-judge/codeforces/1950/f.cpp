/*
    syxm1

    greedy : pick 2, 1, 0.
    simulate the picking.
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

void MAIN()
{
    int a, b, c;
    cin >> a >> b >> c;

    int tmp = a;

    int log; for (log = 0; a >= (1 << log); log++) a -= (1 << log); --log;

    int leaf = (1 << (log + 1)) + a;

    a = tmp;

    if (leaf != c) {
        cout << -1 << '\n';
        return;
    }

    int lvl, cap = 1;
    for (lvl = 0; cap; lvl++) {
        int newcap = 0;
        while (cap--) {
            if (a) newcap += 2, a--;
            else if (b) newcap++, b--;
            else if (c) c--;
         }
        cap = newcap;
    }

    cout << lvl - 1 << '\n';
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
