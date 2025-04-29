#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<pair<ll, ll>>> dp(51, vector<pair<ll, ll>>(n));
    rep(i, 0, n){
        dp[0][i] = {a[i], (a[i]+i)%n};
    }
    rep(i, 1, 41){
        rep(j, 0, n){
            ll fi = dp[i-1][j].first+dp[i-1][dp[i-1][j].second].first;
            ll se = (j+fi)%n;
            dp[i][j] = {fi, se};
        }
    }

    ll ans = 0, pos = 0;
    rep(i, 0, 41){
        if((k>>i)&1){
            ans += dp[i][pos].first;
            pos = dp[i][pos].second;
        }
    }
    cout << ans << endl;
    
    return 0;
}