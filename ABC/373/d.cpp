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
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        ll w; cin >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, -w});
    }
    vector<ll> x(n);
    vector<bool> seen(n);
    auto dfs = [&](auto self, int pos, int pre) -> void {
        for(auto [nxt, w]: g[pos]){
            if(nxt == pre) continue;
            // x[nxt]-x[pos] = w
            if(seen[nxt]) continue;
            x[nxt] = x[pos]+w;
            seen[nxt] = true;
            self(self, nxt, pos);
        }
    };
    rep(i, 0, n){
        if(seen[i]) continue;
        dfs(dfs, i, -1);
    }
    rep(u, 0, n){
        for(auto [v, w]: g[u]){
            assert(x[v]-x[u] == w);
        }
    }
    rep(i, 0, n) cout << x[i] << ' ';
    cout << endl;
    
    return 0;
}