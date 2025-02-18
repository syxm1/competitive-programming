// Roads and Libraries

/*
menggunakan dsu untuk mengelompokkan kota yang bisa terhubung.

dalam suatu set, pilih cost minimum untuk membangun perpustakaan yang bisa 
diakses dari semua anggota set.
*/

#include<cstdio>
#include<vector>

using ll = long long;

struct DSU {
    std::vector<int> par, sz;

    void init(int n) {
        sz.assign(n, 1);
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int get(int x) {
        return (par[x] == x ? x : get(par[x]));
    }

    void merge(int u, int v) {
        u = get(u);
        v = get(v);
        if (u != v) {
            if (sz[u] > sz[v]) {
                int temp = u;
                u = v;
                v = temp;
            }
            par[u] = v;
            sz[v] += sz[u];
        }
    }
};

signed main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m, l, r;
        scanf("%d%d%d%d", &n, &m, &l, &r);

        DSU dsu;
        dsu.init(n);

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            if (dsu.get(u) != dsu.get(v)) {
                dsu.merge(u, v);
            }
        }

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            if (dsu.par[i] == i) {
                ans += l + (dsu.sz[i] - 1) * std::min(l, r);
            }
        }

        printf("%lld\n", ans);
    }
}
