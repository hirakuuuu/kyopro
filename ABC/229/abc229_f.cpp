#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(ll i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc229/tasks/abc229_f

/* 
dp[i][0] = i番目の閉路の辺を削除しない
dp[i][1] = i番目の閉路の内、内側の辺(重みa[i])を削除する
dp[i][2] = i番目の閉路の内、外側の辺(重みb[i])を削除する
*/

int main(){
    int n; cin >> n;
    vector<ll> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) cin >> b[i];
    
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(2, 1LL<<60)));
    dp[1][0][0] = a[1];
    dp[1][1][1] = 0;
    rep(i, 2, n+1){
        rep(j, 0, 2){
            rep(k, 0, 2){
                rep(prej, 0, 2){
                    chmin(dp[i][j][k], dp[i-1][prej][k]+(j==0?a[i]:0)+(j==prej?b[i-1]:0));
                }
            }
        }
    }

    ll ans = (1LL<<60);
    rep(j, 0, 2){
        rep(k, 0, 2){
            chmin(ans, dp[n][j][k]+(j==k?b[n]:0));
        }
    }
    cout << ans << endl;

    
    return 0;
}