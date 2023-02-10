#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<string> s(2);
    rep(i, 0, 2) cin >> s[i];

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(3, vector<ll>(3, 0)));
    int start = 0;
    if(s[0][0] == s[1][0]){
        dp[0][0][0] = dp[0][1][1] = dp[0][2][2] = 1;
    }else{
        rep(j, 0, 3){
            rep(k, j+1, 3){
                dp[1][j][k] = dp[1][k][j] = 1;
            }
        }
        start = 1;
    }

    rep(i, 0, n){
        if(s[0][i] != s[1][i]){
            dp[i+1][0][0] = dp[i][1][2]+dp[i][2][1]+dp[i][1][1]+dp[i][2][2];
            dp[i+1][1][1] = dp[i][0][2]+dp[i][2][0];
            dp[i+1][2][2] = dp[i][1][0]+dp[i][0][1];
            rep(j, 0, 3) dp[i+1][j][j] %= MOD_NUM;
            i++;
        }else{
            dp[i+1][0][1]
        }
    }

    ll ans = 0;
    rep(i, 0, 3){
        rep(j, 0, 3){
            ans += dp[n][i][j];
            ans %= MOD_NUM;
        }
    }

    cout << ans << endl;
    
    return 0;
}