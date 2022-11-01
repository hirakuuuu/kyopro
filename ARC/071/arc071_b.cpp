#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc058/tasks/arc071_b

int main(){
    int n, m; cin >> n >> m;
    vector<ll> x(n), y(m);
    vector<ll> x_sum(n+1), y_sum(m+1);
    rep(i, 0, n){
        cin >> x[i];
        x_sum[i+1] = x_sum[i]+x[i];
    }
    rep(i, 0, m){
        cin >> y[i];
        y_sum[i+1] = y_sum[i]+y[i];
    }

    ll x_total = 0, y_total = 0;
    rep(i, 0, n){
        x_total += i*x[i]-x_sum[i];
        x_total %= MOD;
    }
    rep(i, 0, m){
        y_total += i*y[i]-y_sum[i];
        y_total %= MOD;
    }

    ll ans = x_total*y_total%MOD;
    if(ans < 0) ans += MOD;
    cout << ans << endl;

    return 0;
}