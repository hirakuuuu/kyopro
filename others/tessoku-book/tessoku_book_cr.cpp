#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cr

int main(){
    ll n, W; cin >> n >> W;
    vector<int> v(n+1), w(n+1);
    rep(i, 1, n+1) cin >> w[i] >> v[i];

    vector<vector<ll>> dp(n+1, vector<ll>(100005, (1LL<<60)));
    dp[0][0] = 0;
    rep(i, 1, n+1){
        rep(j, 0, 100005){
            if(j >= v[i]) dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    ll ans = -1;
    rep(i, 0, 100005){
        if(dp[n][i] <= W) ans = i;
    }
    cout << ans << endl;
    
    return 0;
}