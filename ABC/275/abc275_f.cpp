#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc275/tasks/abc275_f

int main(){
    int n, m; cin >> n >> m;

    vector<int> a(n+1);
    int total = 0;
    rep(i, 1, n+1){
        cin >> a[i];
        total += a[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
    vector<vector<int>> dp_(n+1, vector<int>(m+1, 1e9));
    rep(i, 0, n+1) dp[i][0] = 1;
    dp[1][a[1]] = 1;
    dp_[1][a[1]] = 1;
    rep(i, 2, n+1){
        rep(j, 1, m+1){
            // i番目を使う
            if(j >= a[i]) dp_[i][j] = min(dp_[i-1][j-a[i]], dp[i-2][j-a[i]]+1);

            // i番目までを使う
            if(j >= a[i]) dp[i][j] = min(dp[i-1][j], min(dp_[i-1][j-a[i]], dp[i-2][j-a[i]]+1));
            else dp[i][j] = dp[i-1][j];
        }
    }


    rep(i, 1, m+1){
        if(dp[n][i] == 1e9) cout << -1 << endl;
        else cout << min(dp[n][i], dp_[n][i]-1) << endl;
    }
    
    return 0;
}