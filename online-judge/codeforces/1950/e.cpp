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

    string s;
    cin >> s;

    int ans = n;

    for(int l = 1; l * l <= n; l++) {
        if(n % l == 0) {
            map<string, int> s1, s2;

            for(int i = 0; i < n; i += l) s1[s.substr(i, l)]++;
            for(int i = 0; i < n; i += n / l) s2[s.substr(i, n / l)]++;

            if((int) s1.size() == 1) {
                ans = min(ans, l);
            } else if((int) s1.size() == 2) {
                int c1 = (*s1.begin()).second;
                int c2 = (*next(s1.begin())).second;
                string ss = (*s1.begin()).first;
                string tt = (*next(s1.begin())).first;

                int dif = 0;
                for(int i = 0; i < (int) ss.size(); i++)
                    dif += (ss[i] != tt[i]);

                if(dif <= 1 && (c1 == 1 || c2 == 1)) ans = min(ans, l);
            }

            if((int) s2.size() == 1) {
                ans = min(ans, n/l);
            } else if((int) s2.size() == 2) {
                int c1 = (*s2.begin()).second;
                int c2 = (*next(s2.begin())).second;
                string ss = (*s2.begin()).first;
                string tt = (*next(s2.begin())).first;

                int dif = 0;
                for(int i = 0; i < (int) ss.size(); i++)
                    dif += (ss[i] != tt[i]);

                if(dif <= 1 && (c1 == 1 || c2 == 1)) ans = min(ans, n/l);
            }
        }
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
