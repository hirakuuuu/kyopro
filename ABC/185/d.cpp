#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m+2);
    a[0] = 0;
    rep(i, 0, m) cin >> a[i+1];
    a[m+1] = n+1;
    if(n==m){
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    int min_w = n+1;
    rep(i, 0, m+1){
        if(a[i+1]-a[i] == 1) continue;
        min_w = min(min_w, a[i+1]-a[i]-1);
    }
    int ans = 0;
    rep(i, 0, m+1){
        ans += (a[i+1]-a[i]-1)/min_w;
        if((a[i+1]-a[i]-1)%min_w) ans++;

    }
    cout << ans << endl;
}