#include<iostream>
#include<vector>

#define ls(x) (x & (-x))

using ll = long long;

struct fenwick {
    int num;
    std::vector<ll> arr, fen;

    fenwick(int sz) {
        num = sz;
        arr.assign(sz, 0);
        fen.assign(sz, 0);
    } 

    void add(int i, ll d) {
        arr[i] += d;
        while (i < num) {
            fen[i] += d;
            i += ls(i);
        }
    }

    void upd(int i, ll v) {
        add(i, v - arr[i]);
        arr[i] = v;
    } 

    ll pref(int i) {
        ll ret = 0;
        while (i > 0) {
            ret += fen[i];
            i -= ls(i);
        }
        return ret;
    }

    ll sum(int l, int r) {
        return pref(r) - pref(l - 1);
    }
};

int n, q, u, v, s, x, que, timer = 1;
std::vector<ll> val;
std::vector<int> tin, tout;
std::vector<std::vector<int>> adj;

void dfs(int cur, int pre) {
    tin[cur] = timer++;
    for (int nxt : adj[cur]) {
        if (nxt != pre) dfs(nxt, cur);
    }   
    tout[cur] = timer;
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> q;

    val.resize(n);
    tin.resize(n);
    tout.resize(n);
    adj.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        std::cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    fenwick f(n+1);

    for (int i = 0; i < n; i++) {
        f.upd(tin[i], val[i]);
    }

    while (q--) {
        std::cin >> que;

        if (que == 1) {
            std::cin >> s >> x;
            f.upd(tin[--s], x);
        }

        else {
            std::cin >> s; --s;
            std::cout << f.sum(tin[s], tout[s] - 1) << '\n';
        }   
    }
}
