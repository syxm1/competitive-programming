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
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<vector<pii>> v(3, vector<pii>(n));
        for(int i = 0; i < n; i++) {cin >> v[0][i].fi; v[0][i].se = i;}
        for(int i = 0; i < n; i++) {cin >> v[1][i].fi; v[1][i].se = i;}
        for(int i = 0; i < n; i++) {cin >> v[2][i].fi; v[2][i].se = i;}

        sort(rall(v[0])); sort(rall(v[1])); sort(rall(v[2]));

        vector<int> s = {0, 1, 2};

        int ans = 0;
        do {
            vector<bool> chosen(n, 0);

            int score = 0;
            bool ok = 1;

            for(int x = 0; x < 3; x++) {
                int i = s[x];
                int j = 0;

                while(chosen[v[i][j].se] && j < n) j++;

                if(j==n) {
                    ok = 0;
                    break;
                }

                score += v[i][j].fi;
                chosen[v[i][j].se] = 1;
            }

            if(!ok) continue;
            ans = max(ans, score);
        } while(next_permutation(all(s)));

        cout << ans << endl;
    }

    return 0;
}