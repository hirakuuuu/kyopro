#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc189/tasks/abc189_d

int main(){
    int n; cin >> n;
    vector<string> s(n+1);
    rep(i, 0, n) cin >> s[i+1];

    vector<vector<ll>> dp(n+1, vector<ll>(2));
    dp[0][0] = dp[0][1] = 1;

    rep(i, 1, n+1){
        if(s[i] == "AND"){
            dp[i][0] = 2*dp[i-1][0]+dp[i-1][1];
            dp[i][1] = dp[i-1][1];
        }else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][0]+2*dp[i-1][1];
        }
    }

    cout << dp[n][1] << endl;

    
    return 0;
}