#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc192/tasks/abc192_f

int main(){
    int n; cin >> n;
    ll x; cin >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 9e18;
    rep(i, 1, n+1){
        vector<vector<ll>> dp(i+1, vector<ll>(i, -1));
        dp[0][0] = 0;
        rep(j, 0, n){
            vector<vector<ll>> dp_ = dp;
            rep(k, 0, i){
                rep(l, 0, i){
                    if(dp_[k][l] == -1) continue;
                    chmax(dp[k+1][(l+a[j])%i], dp_[k][l]+a[j]);
                }
            }
        }
        if(dp[i][x%i] == -1) continue;
        chmin(ans, (x-dp[i][x%i])/i);
    }
    cout << ans << endl;
    
    return 0;
}