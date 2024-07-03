/**************************
* syxm1
* created: 2024-06-22 16:22 
**************************/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// konsep dasar binary search: https://www.geeksforgeeks.org/binary-search/ 

const double eps = 1e-6; // gawe handle precission-error

int n;

// jarak euclid
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// fungsi gawe nentukno misal jari-jarine 'r', piro kotak sing kenek.
int f(double r) {
    double px = r/2.00, py = 0; // titik pusat lingkaran
    int ret = 0; // hasil akhir (cuma x positif)
    for (int x = 0; x <= (int) r/2 + r; x++) { // iterasi x dari 0 sampai sisi kanan lingkaran
        if ((double) x == px || (double) x == px + 0.5) continue; // handle kalo titik sekarang tepat diatas pusat, atau kehitung dua kali
        // binary search gawe nyari y paling tinggi dengan x sekarang
        int lo = 0, hi = 40000, cnt = 0; // cnt: y paling tinggi
        while (lo <= hi) {
            int y = (lo + hi) >> 1;
            if (dist(x, y, px, py) <= r + eps) { // jarak (x,y) ke pusat (px, py) <= r, onok eps gawe jogo2, soale presisi c++ elek
                lo = y+1;
                cnt = y;
            } else {
                hi = y-1;
            }
        }
        ret += 2 * cnt; // nambah ke hasil akhir 2x, karena y negatif belum kehitung
    }
    return 2 * ret; // kembalikan 2 * ret, karena x negatif belum kehitung di atas
}

void test_case() {
    cin >> n;
    
    // binary search jawaban
    int lo = 0, hi = 40000, ans = 40000; // ans: jawaban akhir
    while(lo <= hi) {
        int md = (lo + hi) >> 1;
        if (f(md) >= n) { // kalo jumlah kotak dengan jari2 md>=n
            hi = md - 1;
            ans = md;
        } else {
            lo = md + 1;
        }
    }

    cout << ans << '\n';
}

signed main() {
    int tc = 1;
    // cin >> tc;

    while (tc--) {
        test_case();
    }
}
