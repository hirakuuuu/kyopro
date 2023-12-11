#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;
const ll INF = (ll)9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
// 問題
// https://atcoder.jp/contests/abc288/tasks/abc288_e

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n+1), c(n+1);
    vector<bool> x(n+1);
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) cin >> c[i];
    rep(i, 0, m){
        int X; cin >> X;
        x[X] = true;
    }

    vector<ll> dp(n+1, INF);
    dp[0] = 0;
    int cnt = 0;
    rep(i, 1, n+1){
        ll mi = INF;
        vector<ll> dp_ = dp;
        if(x[i]){
            rep(j, 1, i+1){
                chmin(mi, c[i-j+1]);
                if(j > cnt) dp[j] = dp_[j-1]+a[i]+mi;
            }
            dp[cnt] = INF;
            cnt++;
        }else{
            rep(j, 1, i+1){
                chmin(mi, c[i-j+1]);
                chmin(dp[j], dp_[j-1]+a[i]+mi);
            }
        }
    }

    ll ans = INF;
    rep(i, 0, n+1) chmin(ans, dp[i]);
    cout << ans << endl;

    return 0;
}