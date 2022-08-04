#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc262/tasks/abc262_d

int main(){
    ll n; cin >> n;
    vector<int> a(n+1);
    rep(i, 0, n) cin >> a[i];

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1)));

    ll ans = 0;
    rep(i, 1, n+1){
        vector dp(n+1, vector(i+1, vector<int>(i, 0)));
        dp[0][0][0] = 1;
        rep(j, 0, n){
            rep(k, 0, i+1){
                rep(l, 0, i){
                    dp[j+1][k][l] += dp[j][k][l];
                    dp[j+1][k][l] %= mod;
                    if(k!=i){
                        dp[j+1][k+1][(l+a[j])%i] += dp[j][k][l];
                        dp[j+1][k+1][(l+a[j])%i] %= mod;
                    }
                }
            }
        }
        ans += dp[n][i][0];
        ans %= mod;
    }

    cout << ans << endl;

    
    
    return 0;
}