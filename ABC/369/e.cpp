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
    vector<vector<pair<ll, ll>>> g(n);
    vector<vector<ll>> e(m);
    vector<ll> w(m);
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    rep(i, 0, n) d[i][i] = 0;
    rep(i, 0, m){
        ll u, v, t; cin >> u >> v >> t;
        u--, v--;
        e[i] = {u, v};
        w[i] = t;
        chmin(d[u][v], t);
        chmin(d[v][u], t);
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }
    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                chmin(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        vector<ll> b(k);
        rep(i, 0, k){
            cin >> b[i];
            b[i]--;
        }
        ll ans = INF;
        do{
            vector<ll> tmp = {d[0][e[b[0]][1]]+w[b[0]], d[0][e[b[0]][0]]+w[b[0]]};
            rep(i, 1, k){
                vector<ll> tmp_(2);
                tmp_[0] = min(tmp[0]+d[e[b[i-1]][0]][e[b[i]][1]], tmp[1]+d[e[b[i-1]][1]][e[b[i]][1]])+w[b[i]];
                tmp_[1] = min(tmp[0]+d[e[b[i-1]][0]][e[b[i]][0]], tmp[1]+d[e[b[i-1]][1]][e[b[i]][0]])+w[b[i]];
                swap(tmp, tmp_);
            }
            tmp[0] += d[e[b[k-1]][0]][n-1];
            tmp[1] += d[e[b[k-1]][1]][n-1];
            chmin(ans, min(tmp[0], tmp[1]));
        }while(next_permutation(b.begin(), b.end()));
        cout << ans << endl;
    }
    
    return 0;
}