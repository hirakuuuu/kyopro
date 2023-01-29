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

// 問題
// https://atcoder.jp/contests/agc033/tasks/agc033_a

int main(){
    int h, w; cin >> h >> w;
    vector<string> a(h);
    rep(i, 0, h) cin >> a[i];

    vector<vector<int>> dp(h+2, vector<int>(w+2, iinf));
    rep(i, 0, h){
        rep(j, 0, w){
            if(a[i][j] == '#') dp[i+1][j+1] = 0;
        }
    }

    rep(i, 1, h+1){
        rep(j, 1, w+1){
            dp[i][j] = min(dp[i][j], min(dp[i-1][j]+1, dp[i][j-1]+1));
        }
    }
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            dp[i][w-j+1] = min(dp[i][w-j+1], min(dp[i-1][w-j+1]+1, dp[i][w-j+2]+1));
        }
    }
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            dp[h-i+1][j] = min(dp[h-i+1][j], min(dp[h-i+2][j]+1, dp[h-i+1][j-1]+1));
        }
    }
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            dp[h-i+1][w-j+1] = min(dp[h-i+1][w-j+1], min(dp[h-i+2][w-j+1]+1, dp[h-i+1][w-j+2]+1));
        }
    }

    

    int ans = 0;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}