#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc100/tasks/abc100_d

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i, 0, n) cin >> x[i] >> y[i] >> z[i];

    ll ans = 0;

    rep(i, 0, 8){
        vector<ll> w = {1LL, 1LL, 1LL};
        rep(j, 0, 3){
            if((i&(1<<j))) w[j] = -w[j];
        }

        vector<vector<ll>> dp(n+1, vector<ll>(m+1, -(1LL<<60)));
        dp[0][0] = 0;
        


        rep(j, 1, n+1){
            dp[j][0] = 0;
            ll val = w[0]*x[j-1]+w[1]*y[j-1]+w[2]*z[j-1];
            rep(k, 1, min((ll)j+1, m+1)){
                dp[j][k] = max(dp[j-1][k], dp[j-1][k-1]+val);
            }
        }

        ans = max(ans, dp[n][m]);
    }

    cout << ans << endl;
    
    return 0;
}