#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc267/tasks/abc267_d

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, -(1LL<<50)));
    rep(i, 0, n+1) dp[i][0] = 0;

    rep(i, 1, n+1){
        rep(j, 1, m+1){
            if(i < j) break;
            if(j < i) dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+j*a[i-1]);
            else dp[i][j] = dp[i-1][j-1]+j*a[i-1];
        }
    }

    cout << dp[n][m] << endl;
    
    return 0;
}