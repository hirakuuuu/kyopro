#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc075/tasks/abc075_d

int main(){
    int n, k; cin >> n >> k;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    
    set<ll> xx, yy;
    rep(i, 0, n){
        xx.insert(x[i]);
        yy.insert(y[i]);
    }
    ll ans = -1;

    for(auto sx: xx) for(auto sy: yy) for(auto tx: xx) for(auto ty: yy){
        if(sx < tx and sy < ty){
            ll s = (tx-sx)*(ty-sy);
            int c = 0;
            rep(i, 0, n){
                if(sx <= x[i] and x[i] <= tx and sy <= y[i] and y[i] <= ty) c++;
            }
            if(c >= k){
                if(ans < 0) ans = s;
                else ans = min(ans, s);
            }
        }
    }
    cout << ans << endl;

    return 0;
}