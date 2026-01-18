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
    vector<vector<int>> g(n);
    rep(_, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> w(n), a(n);
    rep(i, 0, n) cin >> w[i];
    rep(i, 0, n) cin >> a[i];

    vector<int> node(n);
    iota(node.begin(), node.end(), 0);
    sort(node.begin(), node.end(), [&](int i, int j){
        return w[i] < w[j];
    });


    vector<ll> mx(n);
    rep(i, 0, n){
        int u = node[i];
        vector<ll> dp(w[u], 1);

        for(auto v: g[u]){
            if(w[v] >= w[u]) continue;
            rrep(j, w[u]-1-w[v], 0){
                chmax(dp[j+w[v]], dp[j]+mx[v]);
            }
        }
        rep(j, 0, w[u]){
            chmax(mx[u], dp[j]);
        }
        // cout << u << ' ' << mx[u] << endl;
    }
    ll ans = 0;
    rep(i, 0, n) ans += a[i]*mx[i];
    cout << ans << endl;


    return 0;
}