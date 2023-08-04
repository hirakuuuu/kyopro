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
// https://atcoder.jp/contests/abc288/tasks/abc288_e


int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n), c(n), x(m), p(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, m){
        cin >> x[i];
        x[i]--;
        p[x[i]] = 1;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 9e18));
    dp[0][0] = 0;
    rep(i, 0, n){
        ll cur_c = c[i];
        rep(j, 0, i+1){
            chmin(dp[i+1][j+1], dp[i][j]+a[i]+cur_c);
            if(!p[i]){
                chmin(dp[i+1][j], dp[i][j]);
            }
            if(j < i){
                chmin(cur_c, c[i-j-1]);
            }
        }
    }

    ll ans = 9e18;
    rep(i, 0, n+1) chmin(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}