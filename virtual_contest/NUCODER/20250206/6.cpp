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

ll ans = 0;

class UnionFind {
    vector<ll> parent, maxi, mini;
    vector<ll> a, b;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_, vector<int> A, vector<int> B): parent(n_, -1), maxi(n_), mini(n_), a(n_), b(n_){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
        for(auto aa: A) a[aa]++;
        for(auto bb: B) b[bb]++;
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

        a[rx] += a[ry];
        b[rx] += b[ry];

        if(a[rx] >= b[rx]){
            ans += w*b[rx];
            a[rx] -= b[rx];
            b[rx] = 0;
        }else{
            ans += w*a[rx];
            b[rx] -= a[rx];
            a[rx] = 0;
        }
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
    vector<tuple<ll, int, int>> edges(m);
    rep(i, 0, m){
        int u, v; cin >> u >> v; u--, v--;
        ll w; cin >> w;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());

    vector<int> A(k), B(k);
    rep(i, 0, k) cin >> A[i], A[i]--;
    rep(i, 0, k) cin >> B[i], B[i]--;
    UnionFind uf(n, A, B);

    rep(i, 0, m){
        auto [w, u, v] = edges[i];
        uf.unite(u, v, w);
    }
    cout << ans << endl;
    
    return 0;
}