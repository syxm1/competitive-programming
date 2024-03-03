/*
    syxm1

    - the maximum number of '1' taken is 2, otherwise take '3' 1 times.
    - the maximum number of '3' taken is 1, otherwise take '6' 1 times.
    - the maximum number of '6' taken is 4, otherwise take '15' 2 times.
    - the maximum number of '10' taken is 2, otherwise take '15' 2 times.

    brute-force all the possible number of '1', '3', '6', and '10' taken.
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
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// pbds
template<typename T> using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using decreasing_ordered_set =
    tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using decreasing_ordered_multiset =
    tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook(x) order_of_key(x)
#define fbo(x) find_by_order(x)

#define fi first
#define se second
#define sz(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define getunique(v) v.erase(unique(all(v)), v.end())
#define fixprecision(x) cout << fixed << setprecision(x)

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front

template<typename... T> void get_input(T&... args) { ((cin >> args), ...);}

inline namespace Debug {
    template<typename T> void debug(string s, T x) {cerr << "\033[1;34m" << s << "\033[0;32m = \033[35m" << x << "\033[0m\n";}
    template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++)
        if (s[i] == '(' || s[i] == '{') b++;
        else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0)
            {cerr << "\033[1;34m" << s.substr(0, i) << "\033[0;32m = \033[35m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
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

inline namespace FileIO {
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0);
        if (sz(s)) {
            freopen((s+".in").c_str(),"r",stdin);
            freopen((s+".out").c_str(),"w",stdout);
        }
    }
}

#define MOD // toggle mod
#ifdef MOD
    const int mod = 1000000007;
#else
    const int mod = 998244353;
#endif

inline namespace Modular { // source : "https://codeforces.com/blog/entry/63903"
    template <int mod> struct mint {
        int value;
        static const int MOD_value = mod;

        mint(long long v = 0) { value = v % mod; if (value < 0) value += mod;}
        mint(long long a, long long b) : value(0){ *this += a; *this /= b;}

        mint& operator+=(mint const& b) {value += b.value; if (value >= mod) value -= mod; return *this;}
        mint& operator-=(mint const& b) {value -= b.value; if (value < 0) value += mod;return *this;}
        mint& operator*=(mint const& b) {value = (long long)value * b.value % mod;return *this;}

        friend mint mexp(mint a, long long e) {
            mint res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
            return res;
        }
        friend mint inverse(mint a) { return mexp(a, mod - 2); }

        mint& operator/=(mint const& b) { return *this *= inverse(b); }
        friend mint operator+(mint a, mint const b) { return a += b; }
        friend mint operator-(mint a, mint const b) { return a -= b; }
        friend mint operator-(mint const a) { return 0 - a; }
        friend mint operator*(mint a, mint const b) { return a *= b; }
        friend mint operator/(mint a, mint const b) { return a /= b; }
        friend std::ostream& operator<<(std::ostream& os, mint const& a) {return os << a.value;}
        friend bool operator==(mint const& a, mint const& b) {return a.value == b.value;}
        friend bool operator!=(mint const& a, mint const& b) {return a.value != b.value;}
    };
}

//constant
const ld eps = 1e-9, pi = acos(-1);
const int inf = 2e9;
const ll INF = 1e18;

// const int dx[4] = {-1, 0, 1, 0}; // clockwise
// const int dy[4] = {0, 1, 0, -1}; // starting from N
// const int ddx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}; // clockwise
// const int ddy[8] = {-1, 0, 1, 1, 1, 0, -1, -1}; // starting from NW

#define endl "\n"

void solve(int tc) {
    int n;
    cin >> n;

    int ans = inf;
    for(int a = 0; a <= 2; a++) for(int b = 0; b <= 1; b++) for(int c = 0; c <= 4; c++) for(int d = 0; d <= 2; d++) {
        int sum = a + 3 * b + 6 * c + 10 * d;
        if(sum <= n && (n - sum) % 15 == 0) ans = min(ans, a + b + c + d + (n - sum) / 15);
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
