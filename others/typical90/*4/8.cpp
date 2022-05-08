#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_h

/*
部分文字列の個数　→　dp
・前から’a', 'at', ... , 'atcoder' を作れる個数をカウントしていく
・s[i] in 'atcoder'　であれば数を増やす
*/

int main(){
    int n; cin >> n;
    string s; cin >> s;
    string t = "atcoder";
    vector<vector<ll>> dp(n+1, vector<ll>(8));
    dp[0][0] = 1;

    rep(i, 1, n+1){
        dp[i][0] = 1;
        rep(j, 1, 8){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                dp[i][j] %= MOD;
            }else dp[i][j] = dp[i-1][j];
        }
    }
    
    cout << dp[n][7] << endl;
    
    return 0;
}