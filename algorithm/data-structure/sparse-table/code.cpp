#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mxN = 1e5+5;

vector<int> lg(mxN);

void get_log() {
    lg[1] = 0;
    for (int i = 2; i < mxN; i++) {
        lg[i] = lg[i/2] + 1;
    }
}

template<typename T> struct sparse {
    const size_t B = 20; // bit
    size_t n;
    vector<vector<T>> table;

    sparse(size_t sz) {
        this->n = sz;
    }

    sparse(vector<T> v) {
        this->n = v.size();
        table.assign(B, vector<T>(n));
        for (size_t i = 0; i < v.size(); i++) {
            table[0][i] = v[i];
        }
        compute();
    }

    void compute() {
        for (size_t i = 1; i < B; i++) {
            for (size_t j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = min(table[i-1][j], table[i-1][j+(1<<(i-1))]);
            }
        }
    }

    T que(size_t l, size_t r) {
        int i = lg[r - l + 1];
        return min(table[i][l], table[i][r-(1<<i)+1]);
    }
};

void test_case() {
    vector<int> a = {1, 3, 2, 4, 9, 7, 2};
    sparse st(a);
    cout << st.que(1, 4) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    get_log();

    int tc = 1;
    // cin >> tc;

    while (tc--) {
        test_case();
    }
}
