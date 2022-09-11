#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_h

int main(){
    int h, w; cin >> h >> w;
    vector<vector<bool>> a(h+1, vector<bool>(w+1));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            char c; cin >> c;
            if(c == '.') a[i][j] = true;
        }
    }

    vector<vector<ll>> dp(h+1, vector<ll>(w+1));
    dp[1][1] = 1;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(i*j == 1) continue;
            if(a[i][j]){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout << dp[h][w] << endl;

    return 0;
}