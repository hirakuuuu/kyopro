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
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
    }
    int q; cin >> q;
    vector<int> query(q);
    vector<int> inq(m);
    rep(i, 0, q){
        cin >> query[i];
        query[i]--;
        inq[query[i]] = 1;
    }
    
    UnionFind uf(n);
    rep(i, 0, m){
        if(inq[i]) continue;
        uf.unite(u[i], v[i]);
    }

    vector<ll> ans(q);
    ll tot = 0;
    rep(i, 0, n){
        if(uf[i] != i) continue;
        tot += uf.size(i)*(uf.size(i)-1)/2;
    }
    rrep(i, q-1, 0){
        ans[i] = (ll)n*(n-1)/2-tot;
        int qi = query[i];
        if(!uf.same(u[qi], v[qi])){
            tot -= uf.size(u[qi])*(uf.size(u[qi])-1)/2;
            tot -= uf.size(v[qi])*(uf.size(v[qi])-1)/2;
            uf.unite(u[qi], v[qi]);
            tot += uf.size(u[qi])*(uf.size(u[qi])-1)/2;
        }
    }
    rep(i, 0, q){
        cout << ans[i] << endl;
    }

    
    return 0;
}