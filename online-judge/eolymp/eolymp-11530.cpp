// Superhero
/*
menggunakan matrix exponentiation untuk mendapatkan hasil akhir.
*/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e7+9, N = 1e5+5;
using ll = long long;

int n;
ll a[N], b[N], A[3], H[3], T[3][3], E[3][3];

void set_initial(int x) {
    A[0] = A[1] = x;
    A[2] = 1;
}

void set_transition(int y) {
    T[0][0] = T[0][1] = T[2][0] = T[2][1] = y;
    T[1][0] = T[1][1] = T[2][2] = 1;
    T[0][2] = T[1][2] = 0;
}

void set_zero(ll Z[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Z[i][j] = 0;
        }
    }
}

void mul_3x3_E_T() {
    ll Z[3][3];

    set_zero(Z);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                Z[i][j] += (E[i][k] * T[k][j]) % mod;
                Z[i][j] %= mod;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            E[i][j] = Z[i][j];
        }
    }
}

void mul_3x3_T() {
    ll Z[3][3];

    set_zero(Z);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                Z[i][j] += (T[i][k] * T[k][j]) % mod;
                Z[i][j] %= mod;
            }
        }
    }

     for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            T[i][j] = Z[i][j];
        }
    }
}

void mul_1x3() {
    memset(H, 0, sizeof(H));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            H[i] += (A[j] * E[j][i]);
            // cout << i << ' ' << j << ' ' << A[j] << ' ' << E[i][j] << '\n';
            H[i] %= mod;
        }
    }
}

void reset_E() {
    set_zero(E);
    for (int i = 0; i < 3; i++) {
        E[i][i] = 1;
    }
}

void mexp(int x) {
    reset_E();

    while (x) {
        if (x & 1) mul_3x3_E_T();
        mul_3x3_T();
        x >>= 1;
    }

    // cout << "E:\n";
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << E[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

signed main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll x = 0;

    for (int i = 0; i < n; i++) {
        set_initial(x);
        set_transition(a[i]);
        mexp(b[i]);
        mul_1x3();
        // cout << "A:\n";
        // for (int i = 0; i < 3; i++) {
        //     cout << A[i] << ' '; 
        // } cout << '\n';
        // cout << "H:\n";
        // for (int i = 0; i < 3; i++) {
        //     cout << H[i] << ' '; 
        // } cout << '\n';
        x = H[0];
    }

    cout << x << '\n';
}
