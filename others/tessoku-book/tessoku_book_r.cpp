#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_r

/*
dp[0]の初期化に注意
*/

int main(){
    int n, s; cin >> n >> s;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<vector<bool>> dp(n+1, vector<bool>(s+1));
    dp[0][0] = true;
    rep(i, 1, n+1){
        rep(j, 0, s+1){
            if(j >= a[i]){
                dp[i][j] = (dp[i-1][j-a[i]] or dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if(dp[n][s]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}