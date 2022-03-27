#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc184/tasks/abc184_f

int main(){
    int n, t; cin >> n >> t;
    vector<ll> b(n/2+n%2), c(n/2);
    rep(i, 0, n/2+n%2) cin >> b[i];
    rep(i, 0, n/2) cin >> c[i];
    set<ll> d;
    rep(i, 0, 1<<(n/2+n%2)){
        ll s = 0;
        rep(j, 0, n/2+n%2){
            if(i&(1<<j)) s += b[j];
        }
        if(s > t) continue;
        d.insert(s);
    }
    ll ans = 0;
    rep(i, 0, 1<<(n/2)){
        ll s = 0;
        rep(j, 0, n/2){
            if(i&(1<<j)) s += c[j];
        }
        if(s > t) continue;
        auto itr = d.upper_bound(t-s);
        if(itr != d.begin()){
            --itr;
            ans = max(ans, *itr+s);
        }else{
            ans = max(ans, s);
        }
    }
    cout << ans << endl;    
    return 0;
}