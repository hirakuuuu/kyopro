#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_d

int main(){
    ll n, W; cin >> n >> W;
    vector<ll> w(n+1), v(n+1);
    rep(i, 1, n+1) cin >> w[i] >> v[i];
    vector<vector<ll>> dp(n+1, vector<ll>(W+1));
    rep(i, 1, n+1){
        rep(j, 0, W+1){
            if(j >= w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][W] << endl;
    
    return 0;
}