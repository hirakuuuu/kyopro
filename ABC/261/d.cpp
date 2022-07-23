#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc261/tasks/abc261_d

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> x(n+1), y(n+1);
    rep(i, 0, n) cin >> x[i];
    rep(i, 0, m){
        int c, Y; cin >> c >> Y;
        y[c] = Y;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1));

    rep(i, 1, n+1){
        rep(j, 1, i+1){
            // 表
            dp[i][j] = dp[i-1][j-1]+x[i-1]+y[j];
            // 裏
            dp[i][0] = max(dp[i][0], dp[i-1][j-1]);   
        }
    }

    ll ans = 0;

    rep(i, 0, n+1){
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;
    return 0;
}