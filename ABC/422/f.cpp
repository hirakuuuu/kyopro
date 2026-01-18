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
    vector<ll> w(n);
    rep(i, 0, n){
        cin >> w[i];
    }
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    rep(i, 0, n) dp[i][0] = w[0]*i;
    rrep(i, n-1, 1){
        rep(j, 0, n){
            for(auto k: g[j]){
                chmin(dp[i-1][k], dp[i][j]+w[k]*(i-1));
            }
        }
    }

    rep(i, 0, n){
        cout << dp[0][i] << endl;
    }
    
    return 0;
}