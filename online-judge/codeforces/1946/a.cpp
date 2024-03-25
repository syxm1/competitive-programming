#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void MAIN()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &i : a) cin >> i;

    sort(a.begin(), a.end());

    int ans = 1;
    for(int i = (n/2) - (n%2==0); i+1 < n; i++) {
        if(a[i+1] == a[i]) ans++;
        else break;
    }

    cout << ans << '\n';
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
