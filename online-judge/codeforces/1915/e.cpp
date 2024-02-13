/*
    maintain a prefix-sum.
    for every a[i], if i is odd, it contributes -a[i] to the sum, otherwise it contributes a[i].
    find a subarray that equals to 0 by iterating i from index 0 to n-1 by checking if prefix-sum that ends at index i has occurred before.
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
        int n;
        cin >> n;
        ll sum = 0;
        map<ll, bool> exist;
        exist[0] = 1;
        bool found = 0;
        for(int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if(i&1) x = -x;
            sum += x;
            if(exist[sum]) {
                found = 1;
            }
            exist[sum] = 1;
        }
        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}
