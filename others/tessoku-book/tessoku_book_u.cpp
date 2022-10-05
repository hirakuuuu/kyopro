#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_u

int a[2005], p[2005];

int main(){
    int n; cin >> n;
    rep(i, 1, n+1) cin >> p[i] >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1));

    rep(i, 1, n){
        rep(j, 1, n-i+1){
            int l = j, r = i+j;
            // 一番左を破壊
            if(l < p[l] and p[l] <= r){
                // ボーナスをもらえる場合
                dp[l][r] = max(dp[l][r], dp[l+1][r]+a[l]);
            }else{
                // もらえない場合
                dp[l][r] = max(dp[l][r], dp[l+1][r]);
            }

            // 一番右を破壊
            if(l <= p[r] and p[r] < r){
                // ボーナスをもらえる場合
                dp[l][r] = max(dp[l][r], dp[l][r-1]+a[r]);
            }else{
                // もらえない場合
                dp[l][r] = max(dp[l][r], dp[l][r-1]);
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}