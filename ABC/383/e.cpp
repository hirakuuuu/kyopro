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
    vector<ll> parent, maxi, mini, a, b;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1), maxi(n_), mini(n_), a(n_), b(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
    ll ans = 0;


    inline void plus_a(ll x){
        a[x]++;
    }
    inline void plus_b(ll x){
        b[x]++;
    }

    inline bool same(ll x, ll y){
        return root(x) == root(y);
    }

    inline void unite(ll x, ll y, ll w){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        if(parent[rx] > parent[ry]) swap(rx, ry);
        parent[rx] += parent[ry];
        parent[ry] = rx;
        maxi[rx] = std::max(maxi[rx],maxi[ry]);
        mini[rx] = std::min(mini[rx],mini[ry]);
        
        rep(_, 0, 2){
            if(a[rx] >= b[ry]){
                ans += w*b[ry];
                a[rx] -= b[ry];
                b[ry] = 0;
            }else{
                ans += w*a[rx];
                b[ry] -= a[rx];
                a[rx] = 0;
            }
            swap(rx, ry);
        }

        a[rx] += a[ry];
        b[rx] += b[ry];

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
    vector<tuple<ll, ll, ll>> edge(m);
    rep(i, 0, m){
        ll u, v, w; cin >> u >> v >> w;
        u--, v--;
        edge[i] = {w, u, v};
    }
    sort(edge.begin(), edge.end());

    UnionFind uf(n);
    rep(i, 0, k){
        int a; cin >> a; a--;
        uf.plus_a(a);
    }
    rep(i, 0, k){
        int b; cin >> b; b--;
        uf.plus_b(b);
    }

    int id = 0;
    while(uf.size(0) != n){
        auto [w, u, v] = edge[id];
        uf.unite(u, v, w);
        id++;
    }
    cout << uf.ans << endl;
    
    return 0;
}