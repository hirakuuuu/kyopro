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

/*
区間反転 → 隣接項が等しいか異なるかを持った数列の2か所を反転させる
今回だと [l, r] を反転 → d[l-1], d[r] を反転
これより、各操作を 頂点 l-1, r を結ぶ辺とみなすと
n+1 頂点の最小全域木を求める問題に帰着される（木DPの要領で根以外の値を自由に決められるので状態数が 2^n）
連結でないと、ある頂点の状態が自由に決められないので、連結であることが実現できるための必要十分条件
*/

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
        maxi[x] = std::max(maxi[x],maxi[y]);
        mini[x] = std::min(mini[x],mini[y]);
    }

    inline ll min(ll x){
        return mini[root(x)];
    }

    inline ll max(int x){
        return mini[root(x)];
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
    vector<tuple<ll, int, int>> e(m);
    rep(i, 0, m){
        ll c; 
        int l, r; cin >> c >> l >> r;
        e[i] = {c, l-1, r};
    }
    sort(e.begin(), e.end());
    UnionFind uf(n+1);
    ll sum = 0;
    rep(i, 0, m){
        auto [c, l, r] = e[i];
        if(uf.same(l, r)) continue;
        sum += c;
        uf.unite(l, r);
    }
    set<int> r;
    rep(i, 0, n+1) r.insert(uf[i]);

    if(r.size() == 1) cout << sum << endl;
    else cout << -1 << endl;


    return 0;
}