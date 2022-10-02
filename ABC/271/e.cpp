#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc271/tasks/abc271_e


int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(m+1), b(m+1), c(m+1);
    rep(i, 1, m+1){
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<ll> e(k+1);
    rep(i, 1, k+1){
        cin >> e[i];
    }

    vector<ll> dp(n+1, (1LL<<60));
    dp[1] = 0;

    rep(i, 1, k+1){
        dp[b[e[i]]] = min(dp[b[e[i]]], dp[a[e[i]]]+c[e[i]]);        
    }

    if(dp[n] == (1LL<<60)) cout << -1 << endl;
    else cout << dp[n] << endl;

    return 0;
}