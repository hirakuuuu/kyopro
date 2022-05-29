#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc253/tasks/abc253_e

ll dp[1005][5005];

int main(){
    int n, m, k; cin >> n >> m >> k;
    ll ans = 0;
    if(k == 0){
        ans = 1;
        rep(i, 0, n){
            ans *= m;
            ans %= mod;
        }
        cout << ans << endl;
        return 0;
    }

    rep(i, 1, m+1) dp[1][i] = 1;

    rep(i, 2, n+1){
        rep(j, 1, m+1){
            if(j-k >= 1){
                dp[i][1] += dp[i-1][j];
                dp[i][j-k+1] += mod-dp[i-1][j];
            }
            if(j+k <= m){
                dp[i][j+k] += dp[i-1][j];
                dp[i][m+1] += mod-dp[i-1][j];
            }
        }

        rep(j, 1, m+1){
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }

    rep(i, 1, m+1){
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
    
    return 0;
}