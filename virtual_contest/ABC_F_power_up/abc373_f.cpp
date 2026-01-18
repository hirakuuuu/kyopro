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
// using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;
constexpr ll MOD = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n, w; cin >> n >> w;

    vector<vector<ll>> f(w+1, vector<ll>(w+1));
    vector<priority_queue<ll>> g(w+1);
    rep(j, 0, n){
        int W, V; cin >> W >> V;
        g[W].push(V-1);
    }
    rep(i, 1, w+1){
        f[i][0] = 0;
        rep(j, 1, w/i+1){
            if(g[i].empty()) break;
            auto val = g[i].top(); g[i].pop();
            f[i][j] = f[i][j-1]+val;
            if(val-2 <= 0) continue;
            g[i].push(val-2);
        }
    }

    vector<ll> dp(w+1);
    rep(i, 1, w+1){
        vector<ll> ndp = dp;
        rep(j, 0, w+1){
            if(j > 0) chmax(ndp[j], ndp[j-1]);
            rep(k, 1, w/i+1){
                if(j+i*k <= w) chmax(ndp[j+i*k], dp[j]+f[i][k]);
            }
        }
        swap(ndp, dp);
        // rep(j, 0, w+1){
        //     cout << dp[j] << ' ';
        // }
        // cout << endl;
    }
    cout << dp[w] << endl;


    return 0;
}