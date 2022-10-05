#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ct

int main(){
    int n; cin >> n;
    string s; cin >> s;

    vector<vector<int>> dp(n+1, vector<int>(n+1, 1));

    rep(i, 1, n){
        if(s[i-1] == s[i]) dp[i][i+1] = 2;
    }

    rep(i, 2, n){
        rep(j, 1, n-i+1){
            int l = j, r = i+j;
            dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            if(s[l-1] == s[r-1]){
                dp[l][r] = max(dp[l][r], dp[l+1][r-1]+2);
            }
        }
    }

    cout << dp[1][n] << endl;
    
    return 0;
}