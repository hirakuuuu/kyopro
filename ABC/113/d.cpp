#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc113/tasks/abc113_d

ll dp[105][9];

int main(){
    int h, w, k; cin >> h >> w >> k;
    if(w==1){
        cout << 1 << endl;
        return 0;
    }
    dp[0][0] = 1;
    rep(i, 1, h+1){
        rep(j, 0, 1<<(w-1)){
            bool f = false;
            rep(l, 0, w-2){
                if((1<<l)&j and (1<<(l+1))&j) f = true;
            }
            if(f) continue;
            rep(l, 0, w){
                if(l == 0){
                    if(j&1) dp[i][l] += dp[i-1][l+1];
                    else dp[i][l] += dp[i-1][l];
                }else if(l == w-1){
                    if(j&(1<<(w-2))) dp[i][l] += dp[i-1][l-1];
                    else dp[i][l] += dp[i-1][l];
                }else{
                    if(j&(1<<(l-1))) dp[i][l] += dp[i-1][l-1];
                    else if(j&(1<<l)) dp[i][l] += dp[i-1][l+1];
                    else dp[i][l] += dp[i-1][l];
                }
                dp[i][l] %= MOD;
            }
        }
    }
    cout << dp[h][k-1] << endl;

    
    return 0;
}