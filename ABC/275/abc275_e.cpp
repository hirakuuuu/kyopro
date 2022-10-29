#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc275/tasks/abc275_e

vector<ll> inv(2005);

void init_inv(ll n){
    inv[1] = 1;
    rep(i, 2, n+1){
        inv[i] = mod - inv[mod%i]*(mod/i)%mod;
    }
}

int main(){
    int n, m, k; cin >> n >> m >> k;
    init_inv(2*n);
    vector<vector<ll>> dp(k+1, vector<ll>(n+1));
    dp[0][0] = inv[1];
    rep(i, 1, k+1){
        rep(j, 0, n){
            rep(l, 1, m+1){
                if(j+l > n){
                    dp[i][2*n-(j+l)] += dp[i-1][j]*inv[m]; 
                    dp[i][2*n-(j+l)] %= mod;
                }else{
                    dp[i][j+l] += dp[i-1][j]*inv[m];
                    dp[i][j+l] %= mod;
                }
            }
        }
    }

    ll ans = 0;
    rep(i, 0, k+1){
        ans += dp[i][n];
        ans %= mod;
    }

    cout << ans << endl;
    
    return 0;
}