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
constexpr ll INF = 2e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n; cin >> n;
    ll x; cin >> x;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    ll ans = INF;
    rep(k, 1, n+1){
        vector dp(n+1, vector(k+1, vector<ll>(k, -INF)));
        dp[0][0][0] = 0;
        rep(i, 0, n){
            rep(j, 0, k+1){
                rep(l, 0, k){
                    if(dp[i][j][l] == -INF) continue;
                    chmax(dp[i+1][j][l], dp[i][j][l]);
                    if(j < k) chmax(dp[i+1][j+1][(l+a[i])%k], dp[i][j][l]+a[i]);
                }
            }
        }
        // cout << k << ' ' << dp[n][k][x%k] << endl;
        if(dp[n][k][x%k] == -INF) continue;
        chmin(ans, (x-dp[n][k][x%k])/k);
    }
    cout << ans << endl;
    return 0;
}
