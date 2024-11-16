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
    int n, q; cin >> n >> q;
    UnionFind uf(n);
    vector<int> col(n), cnt(n, 1);
    iota(col.begin(), col.end(), 0);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int x, c; cin >> x >> c; x--, c--;
            cnt[col[uf[x]]] -= uf.size(x);
            col[uf[x]] = c;
            cnt[c] += uf.size(x);

            int mxi = uf.max(x), mii = uf.min(x);
            if(mxi < n-1 && col[uf[mxi+1]] == col[uf[x]]){
                uf.unite(mxi+1, x);
            }
            if(mii > 0 && col[uf[mii-1]] == col[uf[x]]){
                uf.unite(mii-1, x);
            }
        }else{
            int c; cin >> c; c--;
            cout << cnt[c] << endl;
        }
        // rep(i, 0, n){
        //     cout << cnt[i] << ' ';
        // }
        // cout << endl;
    }
    
    return 0;
}