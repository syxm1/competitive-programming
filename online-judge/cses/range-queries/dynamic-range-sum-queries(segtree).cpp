#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
template<typename T> struct SegTree {
    int n;
    vector<T> tree;
 
    void update(int v, int tl, int tr, int id, T val) {
        if(tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) >> 1;
            if(id <= tm) update(2 * v + 1, tl, tm, id, val);
            else update(2 * v + 2, tm + 1, tr, id, val);
            tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
        }
    }
 
    T sum(int v, int tl, int tr, int l, int r) {
        if(tl > r || tr < l) return 0;
        else if(tl >= l && tr <= r) return tree[v];
        int tm = (tl + tr) >> 1;
        return sum(2 * v + 1, tl, tm, l, r) + sum(2 * v + 2, tm+1, tr, l, r);
    }
 
    void update(int id, int val) {
        update(0, 0, n-1, id, val);
    }
 
    T sum(int l, int r) {
        return sum(0, 0, n-1, l, r);
    }
 
    SegTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
    }
 
    SegTree(vector<T> const &a) : SegTree((int) a.size()) {
        tree.resize(4 * n);
        for(int i = 0; i < (int) a.size(); i++) {
            update(i, a[i]);
        }
    }
};
 
 
void MAIN()
{
    int n, q;
    cin >> n >> q;
 
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
 
    SegTree<ll> tree(a);
 
    while(q--) {
        ll a, b, c;
        cin >> a >> b >> c;
 
        if(a == 1) {
            tree.update(--b, c);
        } else {
            cout << tree.sum(--b, -- c) << '\n';
        }
 
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int tc = 1;
    // cin >> tc;
 
    while(tc--) {
        MAIN();
    }
 
    return 0;
}
