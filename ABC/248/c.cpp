#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc248/tasks/abc248_c

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> dp(n+1, vector<ll>(n*m+1));
    rep(i, 1, m+1){
        dp[1][i] = 1;
    }
    rep(i, 2, n+1){
        rep(j, 1, m+1){
            rep(l, j+1, n*m+1){
                dp[i][l] += dp[i-1][l-j];
                dp[i][l] %= mod;
            }
        }
    }
    ll ans = 0;
    rep(i, 1, k+1){
        ans = (ans+dp[n][i])%mod;
    }
    cout << ans << endl;
    
    return 0;
}