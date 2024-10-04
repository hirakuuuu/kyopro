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

class UnionFind {
    vector<ll> parent;
    vector<vector<ll>> maxi;
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_ = 1): parent(n_, -1), maxi(n_){
        // iota(maxi.begin(), maxi.end(), 0);
        rep(i, 0, n_){
            maxi[i].push_back(i);
            rep(j, 0, 9){
                maxi[i].push_back(-2);
            }
        }
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

        // maxi[x], maxi[y] をマージする
        vector<ll> maxi_;
        rep(i, 0, 10) maxi_.push_back(maxi[rx][i]);
        rep(i, 0, 10) maxi_.push_back(maxi[ry][i]);
        sort(maxi_.rbegin(), maxi_.rend());
        rep(i, 0, 10) maxi[rx][i] = maxi[ry][i] = maxi_[i];
    }

    inline ll max(int x, int k){
        return maxi[root(x)][k];
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

};

int main(){
    int n, q; cin >> n >> q;
    UnionFind uf(n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int u, v; cin >> u >> v;
            u--, v--;
            uf.unite(u, v);
        }else{
            int v, k; cin >> v >> k;
            v--, k--;
            cout << uf.max(v, k)+1 << endl;
        }
    }


    
    return 0;
}