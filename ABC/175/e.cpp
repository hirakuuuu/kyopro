#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc175/tasks/abc175_e

ll r, c, k, dp[3005][3005][4], v[3005][3005];

int main(){
    cin >> r >> c >> k;
    rep(i, 0, k){
        int h, w, V; cin >> h >> w >> V;
        v[h][w] = V;
    }

    rep(i, 0, 3005) rep(j, 0, 3005) rep(l, 0, 4) dp[i][j][l] = -1;
    dp[0][0][0] = 0;
    rep(i, 0, r){
        rep(j, 0, c){
            for(int l = 2; l >= 0; l--){
                if(dp[i][j][l] >= 0) dp[i][j][l+1] = max(dp[i][j][l+1], dp[i][j][l]+v[i+1][j+1]);
            }

            rep(l, 0, 4){
                if(dp[i][j][l] >= 0){
                    if(i+1 < r) dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][l]);
                    if(j+1 < c) dp[i][j+1][l] = max(dp[i][j+1][l], dp[i][j][l]);
                }
            }
        }
    }
    ll ans = -1;
    rep(i, 0, 4){
        ans = max(ans, dp[r-1][c-1][i]);
    }
    cout << ans << endl;

    return 0;
}