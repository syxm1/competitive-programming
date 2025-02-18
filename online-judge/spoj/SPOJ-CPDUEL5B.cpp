// Asacoco Prescription

/*
binary search d minimum yang mungkin sehingga memenuhi syarat.
ubah menjadi bentuk p/q dan berikan jawaban sesuai yang diminta soal.
*/

#include<bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << ": " << x << '\n';

using ll = long long;
using db = long double;

const int mod = 1e9+7;

int n;
vector<ll> a;

ll binpow(ll a, ll x) {
	ll ret = 1;
	while (x) {
		if (x & 1) ret = (ret * a) % mod;
		a = (a * a) % mod;
		x >>= 1;
	}
	return ret;
}

pair<ll, ll> to_frac(double number, int cycles = 10, double precision = 1e-9){
    double new_number,whole_part;
    double decimal_part =  number - (int)number;
    int counter = 0;
    
    valarray<double> vec_1{double((int) number), 1}, vec_2{1,0}, temporary;
    
    while(decimal_part > precision & counter < cycles){
        new_number = 1 / decimal_part;
        whole_part = (int) new_number;
        
        temporary = vec_1;
        vec_1 = whole_part * vec_1 + vec_2;
        vec_2 = temporary;
        
        decimal_part = new_number - whole_part;
        counter += 1;
    }
    return {vec_1[0], vec_1[1]};
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	a.resize(n);
	for (int i = 0; i<n ;i++) {
		cin >> a[i];
	}

	db lo = 0, hi = 1e9, d = -1;

	for (int i = 0; i<100; i++) {
		db md = (lo + hi) / 2.00;
		bool ok = 1, greater = 0;
		for (int j = 1; j < n; j++) {
			ll val = (db) a[0] + ((db) j) * md; 
			if (val < a[j]) {
				ok = 0;
				break;
			} else if (val > a[j]) {
				greater = 1; 
				ok = 0;
				break;
			}
		}
		if (ok) {
			hi = md;
			d = md;
		} else {
			if (greater) {
				hi = md;
			} else {
				lo = md;
			}
		}
	}

	if (d == -1) {
		cout << d << '\n';
	} else {
		pair<ll, ll> frac = to_frac(d);
		cout << frac.first * binpow(frac.second, mod - 2) % mod << '\n';
	}
}
