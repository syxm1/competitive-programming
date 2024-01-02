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
        int n;
        cin >> n;
        vector<int> a(n);
        int neg = 0, pos = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] < 0) neg++;
            else if(a[i] > 0) pos++;
        }
        if((pos + neg < n) || (neg & 1)) {
            cout << 0 << endl;
        }else {
            cout << 1 << endl;
            cout << 1 << ' ' << 0 << endl;
        }
        
    }

    return 0;
}
