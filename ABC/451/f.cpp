#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
    int n, q; cin >> n >> q;
    vector<int> col(n, 0);
    vector<vector<int>> cnt(n, vector<int>(2));
    rep(i, 0, n) cnt[i][0] = 1;
    UnionFind uf(n);
    int ans = 0;
    vector<vector<int>> g(n);

    bool ok = true;
    rep(i, 0, q){
        int u, v; cin >> u >> v; u--, v--;
        if(uf.same(u, v)){
            if(col[u] == col[v]) ok = false; 
        }else{
            if(uf.size(u) > uf.size(v)) swap(u, v);
            auto f = [&](auto self, int pos, int pre, int c) -> void {
                col[pos] = c;
                for(auto nxt: g[pos]){
                    if(nxt == pre) continue;
                    self(self, nxt, pos, 1-c);
                }
            };

            ans -= min(cnt[uf[u]][0], cnt[uf[u]][1]);
            ans -= min(cnt[uf[v]][0], cnt[uf[v]][1]);
            int pre = col[u];
            f(f, u, -1, 1-col[v]);
            if(pre != col[u]){
                swap(cnt[uf[u]][0], cnt[uf[u]][1]);
            }
            rep(j, 0, 2) cnt[uf[v]][j] += cnt[uf[u]][j];
            ans += min(cnt[uf[v]][0], cnt[uf[v]][1]);
            uf.unite(v, u);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(ok){
            cout << ans << endl;
        }else{
            cout << -1 << endl;
        }
    }

    return 0;
}