/*
    sort by the ending time.
    use pbds.
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// data type & container
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        int n;
        cin >> n;

        vector<pii> a(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i].fi >> a[i].se;
        sort(all(a), [](pii &a, pii &b) {return a.se < b.se;});

        ordered_set<int> x;

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (ll) x.size() - x.order_of_key(a[i].fi);
            x.insert(a[i].fi);
        }

        cout << ans << endl;    
    }

    return 0;
}
