#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
constexpr ll MOD = 998244353;

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

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
    ll n, q; cin >> n >> q;
    ll x = 0;
    vector<ll> par(n+1);
    vector<vector<int>> g(n+1);
    UnionFind uf(n+1);
    while(q--){
        ll a, b, c; cin >> a >> b >> c;
        ll A = (((a*(1+x))%MOD)%2)+1LL;
        ll B = (((b*(1+x))%MOD)%n)+1LL;
        ll C = (((c*(1+x))%MOD)%n)+1LL;
        // cout << A << ' ' << B << ' ' << C << endl;
        if(A==1LL){
            if(uf.size(B) > uf.size(C)) swap(B, C);
            par[B] = C;
            auto dfs = [&](auto self, int pos, int pre) -> void {
                for(auto nxt: g[pos]){
                    if(nxt == pre) continue;
                    par[nxt] = pos;
                    self(self, nxt, pos);
                }
            };
            dfs(dfs, B, C);
            uf.unite(B, C);
            g[B].push_back(C);
            g[C].push_back(B);
        }else{
            ll ans = 0;
            if(uf.same(B, C)){
                if(par[B] == par[C]){
                    ans = par[B];
                }else{
                    rep(_, 0, 2){
                        if(par[par[B]] == C) ans = par[B];
                        swap(B, C);
                    }
                }
            }
            cout << ans << endl;
            x = ans;
        }
    }

    return 0;
}