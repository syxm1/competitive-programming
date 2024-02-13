/*
    iterate each row & column to check the existence of the letter.
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define endl '\n'

#define MOD // toggle mod
#ifdef MOD
const int mod = 1000000007;
#else
const int mod = 998244353;
#endif

const ld eps = 1e-9;
const ll inf = 1e18;

// const int dx[4]{0, 0, 1, -1};
// const int dy[4]{1, -1, 0, 0};

// USACO
void setIO(str s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s)) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}

int main() { setIO();
    int tc;
    cin >> tc;
    while(tc--) {
        vector<vector<char>> v(3, vector<char>(3));
        int x, y;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> v[i][j];
                if(v[i][j]=='?') {x = i; y = j;}
            }
        }
        map<char, bool> exist;
        for(int j = 0; j < 3; j++) {
            if(j == y) continue;
            exist[v[x][j]]=1;
        }
        if(!exist['A']) cout << "A\n";
        else if(!exist['B']) cout << "B\n";
        else cout << "C\n";
    }
    return 0;
}
