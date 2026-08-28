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
    int n, m, k; cin >> n >> m >> k;
    vector<ll> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i] >> b[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    rep(i, 1, n+1){
        rep(j, b[i], m+1){
            dp[i][j] = a[i];
        }
        rep(j, 0, m+1){
            rep(l, max(1, i-k), i){
                if(j+b[i] <= m) chmax(dp[i][j+b[i]], dp[l][j]+a[i]);
            }
        }
    }

    ll ans = 0;
    rep(i, 0, n+1){
        rep(j, 0, m+1){
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}