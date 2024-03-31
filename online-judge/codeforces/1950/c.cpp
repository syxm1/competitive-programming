/*
    syxm1
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

void MAIN()
{
    string s;
    cin >> s;

    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));

    string suf;
    if(hh < 12) suf = "AM";
    else suf = "PM";

    if(hh == 0) {
        hh = 12;
    } else if(hh > 12) {
        hh -= 12;
    }

    cout << (hh < 10 ? "0" : "") << hh << ':' << (mm < 10 ? "0" : "") << mm << ' ' << suf << '\n';
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
