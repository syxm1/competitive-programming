#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

signed main()
{
    int t = 1;
    // cout << t << '\n';

    while (t--) {
    	
    }
}
