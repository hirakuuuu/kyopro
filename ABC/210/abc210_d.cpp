#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc210/tasks/abc210_d

/*
南東の方に向かって進める
dp: 片方の駅を建設した状態でその駅まで線路を引いてきたときの費用の最小値
    dp[i][j] = min(a[i][j], min(dp[i-1][j], dp[i][j-1])+c);
x : 片方の駅を建設した状態でその駅まで線路を引いてきて、その駅にもう1つの駅を建設するときの費用の最小値
    x[i][j] = min(dp[i-1][j], dp[i][j-1])+c+a[i][j];

aのグリッドを左右反転して、同じことをすれば、南西の方向の場合も求まる。
2つの最小値の内、小さい方を出力。
*/
int main(){
    ll h, w, c; cin >> h >> w >> c;
    vector<vector<vector<ll>>> a(2, vector<vector<ll>>(h+1, vector<ll>(w+1)));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> a[0][i][j];
        }
    }
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            a[1][i][j] = a[0][i][w-j+1];
        }
    }

    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(h+1, vector<ll>(w+1, 1LL<<60)));
    vector<vector<vector<ll>>> x(2, vector<vector<ll>>(h+1, vector<ll>(w+1, 1LL<<60)));
    vector<ll> ans(2, 1LL<<60);
    rep(k, 0, 2){
        rep(i, 1, h+1){
            rep(j, 1, w+1){
                dp[k][i][j] = min(a[k][i][j], min(dp[k][i-1][j]+c, dp[k][i][j-1]+c));
            }
        }
        rep(i, 1, h+1){
            rep(j, 1, w+1){
                x[k][i][j] = a[k][i][j]+min(dp[k][i-1][j], dp[k][i][j-1])+c;
                chmin(ans[k], x[k][i][j]);
            }
        }
    }

    cout << min(ans[0], ans[1]) << endl;

    return 0;
}