#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_c

int main(){
    int n; cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(3)), k(n+1, vector<int>(3));
    rep(i, 1, n+1){
        rep(j, 0, 3) cin >> k[i][j];
        rep(j, 0, 3){
            dp[i][j] = max(dp[i-1][(j+1)%3]+k[i][j], dp[i-1][(j+2)%3]+k[i][j]);
        }
    }
    int ans = 0;
    rep(i, 0, 3) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}