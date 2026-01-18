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

class UnionFind {
    vector<ll> parent, maxi, mini;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1), maxi(n_), mini(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }

    inline bool same(ll x, ll y){
        return root(x) == root(y);
    }

    inline void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        if(parent[rx] > parent[ry]) swap(rx, ry);
        parent[rx] += parent[ry];
        parent[ry] = rx;
        maxi[rx] = std::max(maxi[rx],maxi[ry]);
        mini[rx] = std::min(mini[rx],mini[ry]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return maxi[root(x)];
    }

    inline ll size(ll x){
        return (-parent[root(x)]);
    }

    inline ll operator[](ll x){
        return root(x);
    }

    inline void print(){
        rep(i, 0, (ll)parent.size()) cout << root(i) << " ";
        cout << endl;
    }

    void clear(){
        rep(i, 0, (ll)parent.size()){
            parent[i] = -1;
        }
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
};

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n){
        char c; cin >> c;
        a[i][j] = c-'0';
    }

    vector<vector<int>> par(n, vector<int>(n));
    rep(r, 0, n){
        // r を根としたときの親を求めておく
        auto dfs = [&](auto self, int pos, int pre) -> void {
            // cout << pos << ' ' << pre << endl;
            par[r][pos] = pre;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                self(self, nxt, pos);
            }
        };
        dfs(dfs, r, -1);
    }

    vector<vector<bool>> seen(n, vector<bool>(n));
    UnionFind uf(n);
    rep(i, 0, n){
        rep(j, 0, n){
            if(a[i][j] == 0) continue;
            int pi = i, pj = j;
            while(pi != -1 && pj != -1 && !seen[pi][pj]){
                seen[pi][pj] = seen[pj][pi] = true;
                uf.unite(pi, pj);
                pi = par[j][pi];
                pj = par[i][pj];
            }
        }
    }

    vector<int> x(n);
    rep(i, 0, n) x[i] = uf[i];
    // rep(i, 0, n) cout << x[i] << ' ';
    // cout << endl;

    // vector<vector<int>> dist(n, vector<int>(n));
    vector<vector<pair<int, int>>> p(n);
    rep(r, 0, n){
        p[0].push_back({r, r});
        auto dfs = [&](auto self, int pos, int pre, int d) -> void {
            // cout << pos << ' ' << pre << endl;
            for(auto nxt: g[pos]){
                if(nxt == pre) continue;
                p[d].push_back({r, nxt});
                self(self, nxt, pos, d+1);
            }
        };
        dfs(dfs, r, -1, 1);
    }

    vector<vector<bool>> is_pal(n, vector<bool>(n));
    rep(d, 0, n){
        for(auto [u, v]: p[d]){
            // cout << d << ' ' << u << ' ' << v << ' ' << x[u] << ' ' << x[v] << endl;
            
            if(u == v){
                is_pal[u][v] = true;
            }else if(d == 1){
                if(x[u] == x[v]) is_pal[u][v] = true;
            }else if(x[u] == x[v]){
                int pu = par[v][u], pv = par[u][v];
                if(is_pal[pu][pv]) is_pal[u][v] = true;
            }
        }
    }

    int ans = 0;
    rep(i, 0, n) rep(j, 0, n){
        ans += is_pal[i][j];
    }
    cout << ans << endl;
    
    return 0;
}