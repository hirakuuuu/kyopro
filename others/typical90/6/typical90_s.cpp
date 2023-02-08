#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_s


/*
区間DP
・dp[l][r] = (区間[l, r]を全て取り出すときの最小コスト)
・隣同士を取り出すときのコストで初期化
・区間を徐々に広げていってdp[1][2*n]までやる
*/

int main(){
    int n; cin >> n;
    n *= 2;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1));

    rep(i, 1, n+1){
        rep(j, i, n+1) dp[i][j] = (1<<29);
        if(i < n) dp[i][i+1] = abs(a[i]-a[i+1]);
    }

    for(int i = 3; i <= n; i += 2){
        for(int j = 1; j <= n-i; j++){
            int cl = j, cr = j+i;
            for(int k = cl; k <= cr-1; k++){
                dp[cl][cr] = min(dp[cl][cr], dp[cl][k]+dp[k+1][cr]);
            }
            dp[cl][cr] = min(dp[cl][cr], dp[cl+1][cr-1]+abs(a[cl]-a[cr]));
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}