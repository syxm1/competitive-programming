/**************************
* syxm1
* created: 2024-06-22 16:22 
**************************/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const double eps = 1e-6;

int n;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int f(double r) {
    double px = r/2.00, py = 0;
    int ret = 0; 
    for (int x = 0; x <= (int) r/2 + r; x++) {  
        if ((double) x == px || (double) x == px + 0.5) continue;
        int lo = 0, hi = 40000, cnt = 0; 
        while (lo <= hi) {
            int y = (lo + hi) >> 1;
            if (dist(x, y, px, py) <= r + eps) { 
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
