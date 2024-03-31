/*
    syxm1
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

void MAIN()
{
    int a, b, c;
    cin >> a >> b >> c;

    if(a < b && b < c) {
        cout << "STAIR\n";
    } else if(a < b && b > c) {
        cout << "PEAK\n";
    } else {
        cout << "NONE\n";
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
