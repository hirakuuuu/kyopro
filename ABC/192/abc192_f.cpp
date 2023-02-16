#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc192/tasks/abc192_f

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    vector<ll> amari(n+1);
    rep(i, 1, n+1) amari[i] = x%i;

    ll ans = 1LL<<60;
    rep(k, 1, n+1){
        vector<vector<ll>> dp(k+1, vector<ll>(k, -1));
        dp[0][0] = 0;
        rep(i, 1, n+1){
            vector<vector<ll>> dp_ = dp;
            rep(j, 0, min(i, k)){
                rep(l, 0, k){
                    if(dp_[j][l] == -1) continue;
                    chmax(dp[j+1][(l+a[i])%k], dp_[j][l]+a[i]);
                }
            }
        }
        if(dp[k][amari[k]] > 0) chmin(ans, (x-dp[k][amari[k]])/k);
    }

    cout << ans << endl;

    return 0;
}