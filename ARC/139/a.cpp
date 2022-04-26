#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc139/tasks/arc139_a

int main(){
    int n; cin >> n;
    vector<ll> t(n, 1);
    rep(i, 0, n){
        int T; cin >> T;
        rep(j, 0, T) t[i] *= 2;
    }

    ll ans = 0;
    
    rep(i, 0, n){
        if((ans/t[i])%2) ans = t[i]*(ans/t[i]+2);
        else ans = t[i]*(ans/t[i]+1);
    }
    cout << ans << endl;
    
    return 0;
}