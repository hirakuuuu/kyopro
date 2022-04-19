#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc248/tasks/abc248_f


ll dp[2][3010][2];

int main(){
    ll n, p; cin >> n >> p;




    rep(i, 0, 2){
        rep(j, 0, 3005){
            rep(k, 0, 2) dp[i][j][k] = 0;
        }
    }

    dp[0][0][0] = 1;
    dp[0][1][1] = 1;

    rep(i, 0, n-1){
        rep(j, 0, i+2){
            rep(a, 0, 2) rep(b, 0, 2) rep(c, 0, 2){
                if(a+b+c <= 1) dp[1][j+a+b+c][0] += dp[0][j][0];
                else if(a+b <= 1) dp[1][j+a+b+c][1] += dp[0][j][0];

                if(a+b+c == 0) dp[1][j+a+b+c][0] += dp[0][j][1];
                else if(a+b == 0) dp[1][j+a+b+c][1] += dp[0][j][1];  
            }
        }

        rep(j, 0, i+3){
            rep(k, 0, 2){
                dp[0][j][k] = dp[1][j][k]%p;
                dp[1][j][k] = 0;
            }
        }
    }

    rep(i, 1, n){
        if(i > 1) cout << " ";
        cout << dp[0][i][0];
    }
    cout << endl;

    
    return 0;
}