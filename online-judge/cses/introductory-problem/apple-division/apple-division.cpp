#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int     long long
#define ull     unsigned long long
#define ld      long double
#define pii     pair<int, int>
#define str     string
#define fi      first
#define se      second
// #define oset    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define endl    '\n'

#define len     length
#define pb      push_back
#define ppb     pop_back
#define pf      push_front
#define ppf     pop_front
#define lb      lower_bound
#define ub      upper_bound

#define LSOne(x)   ((x) & (-x))
#define sz(x)	    (int) x.size()
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define ppc(x)     __builtin_popcount(x)
#define ppcll(x)   __builtin_popcountll(x)

#define mod     1000000007 // 1e9+7
#define eps     0.000000001 // 1e-9
#define inf     2147483647 // INT_MAX
#define INF     9223372036854775807 // LLONG_MAX
// const vector<int> dx = {1,-1,0,0,1,-1,-1,1};
// const vector<int> dy = {0,0,-1,1,-1,-1,1,1};

template<typename T> void print(T var, string end = "") {cout << var << end;}
template<typename T> void print(vector<T> var, string end = "") {cout << '['; for(int i = 0; i < var.size(); i++) {print(var[i], (i == var.size() - 1 ? "" : ", "));} cout << ']' << end;}
template<typename T> void print(vector<vector<T>> var, string end = "\n") {for(auto &i : var) {print(i, end);}}
template<typename T, typename U> void print(pair<T, U> var, string end = "") {cout << '[' << var.first << ", " << var.second << ']' << end;}
template<typename T, typename U> void print(vector<pair<T, U>> var, string end = "\n") {for(auto &i : var) {print(i, end);}}
template<typename T, typename U> void print(map<T, U> var, string end = "\n") {for(auto &i : var) {print(i, end);}}

void print() {cout << "\n";}
template <typename T, typename... V> void print(T t, V... v) {print(t); if (sizeof...(v)) cout << ", "; print(v...);}
#define trace(x...) cout << #x << " : " ; print(x); cout << endl

void Main(int tc) { 
    int n, tot = 0;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    int ans = inf;
    for(int mask = 0; mask <= (1 << n) - 1; mask++) {
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            if(mask & (1 << (i - 1))) sum += a[i];
        }
        ans = min(ans, abs(sum - abs(tot - sum)));
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t; 

    for(int tc = 1; tc <= t; tc++) {
        Main(tc);
    }
}

/*

*/
