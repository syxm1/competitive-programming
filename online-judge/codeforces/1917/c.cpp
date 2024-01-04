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
#define rall(v) b.rbegin(), v.rend()

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
        int n, k, d;
        cin >> n >> k >> d; 
        vector<int> a(n+1), b(k+1);
        for(int i = 1 ; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= k; i++) cin >> b[i];
        b[0] = b[k];
        int ans = 0;
        for(int i = 1; i <= d && i <= 2 * n; i++) {
            int score = 0;
            for(int j = 1; j <= n; j++) score += (a[j] == j);
            score += (d - i) / 2;
            ans = max(ans, score);
            for(int j = 1; j <= b[i%k]; j++) a[j]++;
        }   
        cout << ans << endl;
    }
    return 0;
}