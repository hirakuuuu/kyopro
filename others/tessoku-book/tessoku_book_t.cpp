#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_t

int main(){
    string s, t; cin >> s >> t;

    vector<vector<int>> dp(2005, vector<int>(2005));

    rep(i, 1, s.size()+1){
        rep(j, 1, t.size()+1){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i-1] == t[j-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
    }
    cout << dp[s.size()][t.size()] << endl;
    return 0;
}