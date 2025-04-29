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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> cd(n);
    rep(i, 0, n) cin >> cd[i].first >> cd[i].second;
    sort(cd.rbegin(), cd.rend());
    vector<vector<ll>> dp(11, vector<ll>(m+1, -INF));
    dp[0][0] = 0;

    rep(i, 0, n){
        if(cd[i].first == 0) break;
        auto [c, d] = cd[i];
        rrep(j, 10, 1){
            rep(k, 0, m+1){
                if(k-(c<<(j-1)) >= 0) chmax(dp[j][k], dp[j-1][k-(c<<(j-1))]+d);
            }
        }
    }

    ll ans = 0;
    rep(i, 1, 11){
        rep(k, 0, m+1){
            chmax(ans, dp[i][k]);
        }
    }
    rep(i, 0, n){
        if(cd[i].first == 0) ans += cd[i].second;
    }
    cout << ans << endl;
    
    return 0;
}