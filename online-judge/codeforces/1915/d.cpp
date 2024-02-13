/*
    greedy: iterate from n-1 to 0.
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
    map<char, bool> vow;
    vow['a'] = 1;
    vow['e'] = 1; 
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        str s;
        cin >> s;
        str ans = "";
        int len = 0;
        for(int i = n-1; i >= 0;) {
            if(vow[s[i]]) {
                ans.push_back(s[i]);
                ans.push_back(s[i-1]);
                ans.push_back('.'); 
                i-=2;
            } else {
                ans.push_back(s[i]);
                ans.push_back(s[i-1]);
                ans.push_back(s[i-2]);
                ans.push_back('.'); 
                i-=3;
            }
        }
        ans.pop_back();
        reverse(all(ans));
        cout << ans << endl;
    }
    return 0;
}
