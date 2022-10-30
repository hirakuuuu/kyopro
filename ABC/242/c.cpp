#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n; cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(10));
    rep(i, 1, 10) dp[1][i] = 1;
    rep(i, 1, n){
        rep(j, 1, 10){
            if(j == 1) dp[i+1][1] = (dp[i][1]+dp[i][2])%mod;
            else if(j == 9) dp[i+1][9] = (dp[i][8]+dp[i][9])%mod;
            else dp[i+1][j] = (dp[i][j-1]+dp[i][j]+dp[i][j+1])%mod;
        }
    }
    ll ans = 0;
    rep(i, 1, 10) ans = (ans+dp[n][i])%mod;
    cout << ans << endl;
}