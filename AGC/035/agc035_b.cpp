#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    if(m%2){
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> ans;
    vector<vector<int>> t(n);
    vector<int> deg(n);
    UnionFind uf(n);
    rep(i, 0, n){
        rep(j, 0, g[i].size()){
            if(uf.same(i, g[i][j])){
                ans.push_back({i, g[i][j]});
                deg[i]++;
            }else{
                uf.unite(i, g[i][j]);
                t[i].push_back(g[i][j]);
                t[g[i][j]].push_back(i);
            }
        }
    }

    auto dfs = [&](auto self, int pos, int pre) -> void {
        for(auto nxt: t[pos]){
            if(nxt == pre) continue;
            self(self, nxt, pos);
            if(deg[nxt]%2){
                ans.push_back({nxt, pos});
                deg[nxt]++;
            }else{
                ans.push_back({pos, nxt});
                deg[pos]++;
            }
        }
    };
    dfs(dfs, 0, -1);
    for(auto [u, v]: ans){
        cout << u+1 << ' ' << v+1 << endl;
    }
    
    return 0;
}