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

/*
すでに到達している地点は区間に対応する
dp[l][r][2] := 区間 [l, r] にはすでに到達しており、現在 l or r にいるときの移動距離の最小値
*/

int main(){
    int n; cin >> n;
    ll x; cin >> x;
    vector<ll> y(n), z(n);
    rep(i, 0, n) cin >> y[i];
    rep(i, 0, n) cin >> z[i];

    vector<pair<ll, ll>> p(2*n+2); // {位置, （あれば）対応するハンマーの位置}
    rep(i, 0, n){
        p[2*i] = {y[i], z[i]};
        p[2*i+1] = {z[i], 0};
    }
    p[2*n] = {0, 0};
    p[2*n+1] = {x, 0};
    sort(p.begin(), p.end());
    unordered_map<ll, int> id;
    rep(i, 0, 2*n+2) id[p[i].first] = i;

    vector<vector<vector<ll>>> dp(2*n+2, vector<vector<ll>>(2*n+2, vector<ll>(2, INF)));
    dp[id[0]][id[0]][0] = dp[id[0]][id[0]][1] = 0;
    rep(range, 1, 2*n+2){
        rep(l, 0, 2*n+2){
            int r = l+range;
            if(r >= 2*n+2) continue;
            // (l+1, r) -> (l, r)
            if(p[l+1].second == 0 || inr(p[l+1].first, p[l+1].second, p[r].first+1)){
                chmin(dp[l][r][0], dp[l+1][r][0]+abs(p[l].first-p[l+1].first));
                chmin(dp[l][r][0], dp[l+1][r][1]+abs(p[l].first-p[r].first));
            }
            // (l, r-1) -> (l, r)
            if(p[r-1].second == 0 || inr(p[l].first, p[r-1].second, p[r-1].first+1)){
                chmin(dp[l][r][1], dp[l][r-1][0]+abs(p[r].first-p[l].first));
                chmin(dp[l][r][1], dp[l][r-1][1]+abs(p[r].first-p[r-1].first));
            }
        }
    }

    ll ans = INF;
    rep(i, 0, 2*n+2){
        chmin(ans, min(dp[id[x]][i][0], dp[i][id[x]][1]));
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;




    
    return 0;
}