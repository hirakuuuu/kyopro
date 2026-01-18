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
    int n; cin >> n;
    vector<ll> w(n), h(n), b(n);
    rep(i, 0, n){
        cin >> w[i] >> h[i] >> b[i];
    }
    vector<ll> dp(500*500+1, -INF);
    vector<ll> ndp(500*500+1, -INF);
    dp[0] = 0;
    ll tot = 0;
    rep(i, 0, n){
        rep(j, 0, 500*500+1){
            ndp[j] = -INF;
        }
        rep(j, 0, 500*500+1){
            if(dp[j] == -INF) continue;
            if(w[i]+j <= 500*500) chmax(ndp[w[i]+j], dp[j]+b[i]);
            chmax(ndp[j], dp[j]+h[i]);
        }
        swap(ndp, dp);
        tot += w[i];
    }
    ll ans = 0;
    rep(i, 0, 500*500+1){
        if(tot-i <= i) chmax(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}