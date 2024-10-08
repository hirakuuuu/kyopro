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

/*
重さ w のアイテムを k 個使うときの価値の最大値を f_w(k) で表す. 
1 <= k <= W なので, f_w は愚直に前計算可能 O(Wn\log{n})
あとはDP
*/

int main(){
    int n, W; cin >> n >> W;
    vector<ll> w(n), v(n);
    vector<priority_queue<pair<ll, ll>>> g(W+1);
    rep(i, 0, n){
        cin >> w[i] >> v[i];
        g[w[i]].push({v[i]-1, 1});
    }
    vector<vector<ll>> f(W+1, vector<ll>(W+1));
    rep(i, 1, W+1){
        f[i][0] = 0;
        if(g[i].empty()) continue;
        rep(j, 1, W+1){
            if(g[i].top().first > 0){
                f[i][j] = f[i][j-1]+g[i].top().first;
                auto [val, k] = g[i].top(); g[i].pop();
                g[i].push({val-2, k+1});
            }
        }
    }

    vector<ll> dp(W+1);
    rep(i, 1, W+1){
        vector<ll> dp_ = dp;
        rep(k, 1, W/i+1){
            rep(j, 0, W+1){
                if(j+k*i > W) break;
                chmax(dp[j+k*i], dp_[j]+f[i][k]);
            }
        }
    }
    ll ans = 0;
    rep(i, 1, W+1) chmax(ans, dp[i]);
    cout << ans << endl;


    
    
    return 0;
}