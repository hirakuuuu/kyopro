#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc185/tasks/abc185_e

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    rep(i, 0, m+1) dp[0][i] = i;
    rep(i, 0, n+1) dp[i][0] = i;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+(a[i-1] != b[j-1])));
        }
    }
    cout << dp[n][m] << endl;

    
    return 0;
}