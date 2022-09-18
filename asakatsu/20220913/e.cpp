#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc215/tasks/abc215_e

int main(){
    int n; cin >> n;
    string s; cin >> s;

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(1024, vector<ll>(10)));

    rep(i, 1, n+1){
        rep(j, 0, 1024){
            rep(k, 0, 10){
                dp[i][j][k] += dp[i-1][j][k];
                if(s[i-1]-'A' == k) dp[i][j][k] += dp[i-1][j][k];
                dp[i][j][k] %= mod;
                if(j == (1<<(s[i-1]-'A'))){
                    dp[i][j][k]++;
                    dp[i][j][k] %= mod;
                }else if(j&(1<<(s[i-1]-'A')) == 0){
                    dp[i][j+(1<<(s[i-1]-'A'))][s[i-1]-'A'] += dp[i-1][j][k];
                    dp[i][j+(1<<(s[i-1]-'A'))][s[i-1]-'A'] %= mod;
                }
            }
        }
    }

    ll ans = 0;

    rep(j, 1, 1024){
        rep(k, 0, 10){
            ans += dp[n][j][k];
            ans %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}