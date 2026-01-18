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
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    UnionFind uf(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        if(uf.same(u, v)) continue;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        uf.unite(u, v);
    }

    vector<int> c(n);
    vector<int> ans;
    vector<bool> seen(n);
    auto f = [&](auto self, int pos, int pre) -> void {
        seen[pos] = 1;
        for(auto [nxt, eid]: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            if(k != 0 && c[nxt] == 0){
                k += c[nxt]+c[pos];
                ans.push_back(eid);
                c[nxt] = 1-c[nxt];
                c[pos] = 1-c[pos];
                k -= c[nxt]+c[pos];
            }
        }
    };
    rep(i, 0, n){
        if(seen[i]) continue;
        f(f, i, -1);
    }
    // cout << k << endl;
    // rep(i, 0, n){
    //     cout << c[i] << ' ';
    // }
    // cout << endl;

    if(k == 0){
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for(auto aa: ans){
            cout << aa+1 << ' ';
        }
        cout << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}