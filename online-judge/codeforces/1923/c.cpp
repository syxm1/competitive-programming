#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin>>tc;
    while(tc--) {
        int n, q;
        cin>>n>>q;
        vector<int> a(n+1,0), pref(n+1, 0), sum(n+1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i-1] + (a[i]==1);
            sum[i] = sum[i-1] + a[i];
        }
        while(q--){
            int l, r;
            cin >> l >> r;
            int sz = r - l + 1;
            int sm = sum[r] - sum[l-1];
            int cnt = pref[r] - pref[l-1];
            cout << (cnt > sm - sz || sz==1 ? "NO" : "YES") << "\n";        
        }
    }
}
