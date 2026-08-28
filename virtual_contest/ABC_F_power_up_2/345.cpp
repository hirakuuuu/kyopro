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
    vector<vector<int>> g(n);
    vector<unordered_map<int, int>> eid(n);
    UnionFind uf(n);
    rep(i, 0, m){
        int u, v; cin >> u >> v; 
        u--, v--;
        if(uf.same(u, v)) continue;
        uf.unite(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
        eid[u][v] = eid[v][u] = i;
    }

    if(k%2){
        cout << "No" << endl;
        return 0;
    }

    vector<int> col(n);
    vector<int> ans;
    vector<int> seen(n);
    auto f = [&](auto self, int pos, int pre) -> void {
        seen[pos] = 1;
        for(auto nxt: g[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            if(k != 0 && col[nxt] == 0){
                ans.push_back(eid[pos][nxt]);
                k += col[pos];
                col[pos] ^= 1;
                k -= col[pos];
                k += col[nxt];
                col[nxt] ^= 1;
                k -= col[nxt];
                // cout << pos << ' ' << nxt << ' ' << k << endl;
            }
        }
        return;
    };
    rep(i, 0, n){
        if(seen[i]) continue;
        f(f, i, -1);
    }
    if(k != 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for(auto aa: ans){
            cout << aa+1 << ' ';
        }
        cout << endl;
    }
    return 0;
}