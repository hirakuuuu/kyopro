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
    int n; cin >> n;
    vector<tuple<ll, ll, ll>> edges;
    rep(i, 0, n){
        rep(j, i+1, n){
            ll a; cin >> a;
            edges.push_back({a, i, j});
        }
    }
    sort(edges.begin(), edges.end());

    vector<vector<int>> ch(n);
    rep(i, 0, n) ch[i] = {i};
    vector<vector<int>> dist(n, vector<int>(n, IINF));
    rep(i, 0, n) dist[i][i] = 0;
    UnionFind uf(n);
    rep(i, 0, n*(n-1)/2){
        auto [cost, u, v] = edges[i];
        if(uf.same(u, v)){
            if(dist[u][v] != cost){
                cout << "No" << endl;
                return 0;
            }
        }else{
            int rx = uf[u], sz_x = uf.size(u);
            int ry = uf[v], sz_y = uf.size(v);
            uf.unite(u, v);
            for(auto c1: ch[rx]){
                for(auto c2: ch[ry]){
                    dist[c1][c2] = dist[c2][c1] = dist[c1][u]+cost+dist[v][c2];
                }
            }
            if(uf[u] == rx){
                for(auto c: ch[ry]) ch[rx].push_back(c);
            }else{
                for(auto c: ch[rx]) ch[ry].push_back(c);
            }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}