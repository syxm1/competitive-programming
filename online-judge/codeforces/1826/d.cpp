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
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// pbds
template<typename T> using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook(x) order_of_key(x)
#define fbo(x) find_by_order(x)

#define fi first
#define se second
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define getunique(v) v.erase(unique(all(v)), v.end())

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

template<typename... T> void get_input(T&... args) { ((cin >> args), ...);}

inline namespace Debug {
template<typename T> void debug(string s, T x) {cerr << "\033[1;34m" << s << "\033[0;32m = \033[35m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
        if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;34m" << s.substr(0, i)
            << "\033[0;32m = \033[35m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
template<typename T> void debug_nameless(T x) {cerr << "\033[35m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug_nameless(T x, Args... args) {cerr << "\033[35m" << x << "033[31m | "; debug_nameless(args...);}
}

#ifndef ONLINE_JUDGE
#define trace(...) debug(#__VA_ARGS__, __VA_ARGS__)
#define print(...) debug_nameless(__VA_ARGS__)
#else
#define trace(...) 135
#define print(...) 135
#endif

// constant
#define MOD // toggle mod
#ifdef MOD
    const int mod = 1000000007;
#else
    const int mod = 998244353;
#endif

const ld eps = 1e-9;
const int inf = 2e9;
const ll INF = 1e18;

// const int dx[4] = {0, 0, 1, -1};
// const int dy[4] = {1, -1, 0, 0};

// USACO
void setIO(str s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s)) {
        freopen((s+".in").c_str(),"r",stdin);
        freopen((s+".out").c_str(),"w",stdout);
    }
}

#define endl "\n"

void solve(int tc) {
    /*
    problem link : https://codeforces.com/contest/1826/problem/D

    sum = b[i] + b[j] + b[k] - (r - l) = b[i] + b[j] + b[k] + l - r, find maximum sum!

    suppose we have index i, j, k (1 <= i < j < k <= n). we can find the answer by
    brute-forcing all the possible j (2, n-1) and find the maximum a[i] + i (i here same as l)
    and the maximum a[k] - k (k here same as r) so that a[i] + a[j] + a[k] + l - r is maximized.
    j will be only optimum if a[j] is the one of three maximum value in range i and k that chosen.
    (not all compared value is valid to be answer, because a[j] is not always the maximum among index i and k).
    */

    int n;
    cin >> n;

    vector<int> a(n+1) , p(n+1), s(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    p[1] = a[1] + 1;
    s[n] = a[n] - n;

    for(int i = 2; i <= n; i++) p[i] = max(p[i-1], a[i] + i);
    for(int i = n-1; i >= 1; i--) s[i] = max(s[i+1], a[i] - i);

    int ans = 0;
    for(int i = 2; i < n; i++) {
        ans = max(ans, a[i] + p[i-1] + s[i+1]);
    }

    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
auto begin = std::chrono::high_resolution_clock::now();
#endif

setIO();
int tc = 1;
cin >> tc;

for(int i = 1; i <= tc; i++)
    solve(i);

#ifndef ONLINE_JUDGE
auto end = std::chrono::high_resolution_clock::now();
cerr << setprecision(4) << fixed;
cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << "s" << endl;
#endif

return 0;
}
