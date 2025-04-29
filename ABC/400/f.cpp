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
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i], c[i]--;
    vector<ll> x(n);
    rep(i, 0, n) cin >> x[i];


    vector<vector<int>> cpos(n);
    rep(i, 0, n){
        cpos[i].push_back(-1);
    }
    rep(i, 0, 2*n){
        cpos[c[i%n]].push_back(i);
    }

    vector<vector<ll>> dp(2*n+1, vector<ll>(2*n+1, INF));
    rep(i, 0, 2*n+1){
        dp[i][i] = 0;
        if(i+1 <= 2*n) dp[i][i+1] = x[c[i%n]]+1;
    }

    rep(k, 2, n+1){
        rep(l, 0, 2*n-k+1){
            int r = l+k;
            // [l, r)
            if(c[l%n] == c[(r-1)%n]){
                chmin(dp[l][r], dp[l+1][r-1]+x[c[l%n]]+(r-l));
            }
            rep(m, l, r){
                if(l+1 <= m && m+1 <= r && c[l%n] == c[m%n] && c[m%n] == c[(r-1)%n]) chmin(dp[l][r], dp[l][m+1]+dp[m+1][r-1]+(r-l));
                if(l+1 <= m && m+1 <= r && c[l%n] == c[m%n]) chmin(dp[l][r], dp[l+1][m]+dp[m][r]+(m-l));
                if(m+1 <= r-1 && c[(r-1)%n] == c[m%n]) chmin(dp[l][r], dp[l][m]+dp[m][r-1]+(r-m));
                chmin(dp[l][r], dp[l][m]+dp[m][r]);
            }
            // cout << l << ' ' << r << ' ' << dp[l][r] << endl;
        }
    }

    ll ans = INF;
    rep(i, 0, n+1){
        chmin(ans, dp[i][i+n]);
    }
   
    cout << ans << endl;
    return 0;
}