#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_w

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m+1);
    rep(i, 1, m+1){
        rep(j, 0, n){
            int b; cin >> b;
            a[i] += b*(1<<j);
        }
    }

    vector<vector<int>> dp(m+1, vector<int>((1<<n), (1<<30)));
    dp[0][0] = 0;

    rep(i, 1, m+1){
        rep(j, 0, (1<<n)){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);

            // 配る形式のＤＰの考え方でやればOK
            int v = j|a[i];
            dp[i][v] = min(dp[i][v], dp[i-1][j]+1);
        }
    }

    if(dp[m][(1<<n)-1] == (1<<30)) cout << -1 << endl;
    else cout << dp[m][(1<<n)-1] << endl;
    
    return 0;
}