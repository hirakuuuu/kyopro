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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<tuple<int, int, int>> dcs(n);
    rep(i, 0, n){
        int d, c, s; cin >> d >> c >> s;
        dcs[i] = {d, c, s};
    }
    sort(dcs.begin(), dcs.end());
    vector<vector<ll>> dp(n+1, vector<ll>(5005));
    ll ans = 0;
    rep(i, 0, n){
        auto [d, c, s] = dcs[i];
        dp[i+1] = dp[i]; 
        rep(j, 1, d+1){
            if(j-c >= 0) chmax(dp[i+1][j], dp[i][j-c]+s);
        }
    }
    rep(i, 0, 5005) chmax(ans, dp[n][i]);
    cout << ans << endl;
    
    return 0;
}