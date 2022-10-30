#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc215/tasks/abc215_e

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<vector<int>>> dp(1024, vector<vector<int>>(1024, vector<int>(10)));
    rep(i, 1, n+1){
        int l = s[i-1]-'A';
        rep(j, 0, 1<<10){
            rep(k, 0, 10){
                dp[i][j][k] = dp[i-1][j][k];
                if(k == l) dp[i][j][k] += dp[i-1][j][k];
                dp[i][j][k] %= mod;
            }

            if(j&(1<<l)){
                rep(k, 0, 10) dp[i][j][l] = (dp[i][j][l]+dp[i-1][j-(1<<l)][k])%mod;
            }
        }
        dp[i][(1<<l)][l] = (dp[i][(1<<l)][l]+1)%mod;
    }
    int ans = 0;
    rep(j, 0, 1<<10){
        rep(k, 0, 10) ans = (ans+dp[n][j][k])%mod;
    }
    cout << ans << endl;
    return 0;
}