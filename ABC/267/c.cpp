#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc267/tasks/abc267_c

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n), ruiseki(n+1);
    rep(i, 0, n){
        cin >> a[i];
        ruiseki[i+1] = ruiseki[i]+a[i];
    }

    ll ans = 0;
    rep(i, 0, m) ans += (i+1)*a[i];

    ll cnt = ans;

    rep(i, m, n){
        cnt -= (ruiseki[i]-ruiseki[i-m]);
        cnt += a[i]*m;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    
    return 0;
}