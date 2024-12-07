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
    ll n, x, k; cin >> n >> x >> k;
    vector<vector<pair<ll, ll>>> pr(n);
    rep(i, 0, n){
        ll p, u, c; cin >> p >> u >> c;
        c--;
        pr[c].push_back({p, u});
    }

    vector<ll> dp(x+1);
    rep(i, 0, n){
        vector<vector<ll>> ndp(2, vector<ll>(x+1));
        ndp[0] = dp;
        for(auto [p, u]: pr[i]){
            rrep(j, x, p){
                chmax(ndp[1][j], max(ndp[0][j-p]+u+k, ndp[1][j-p]+u));
            }

        }
        rep(j, 0, x+1){
            dp[j] = max(ndp[0][j], ndp[1][j]);
        }
    }
    cout << dp[x] << endl;
    return 0;
}