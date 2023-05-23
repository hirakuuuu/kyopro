#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
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
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(m+q), b(m+q), c(m+q);
    vector<vector<int>> edge;
    rep(i, 0, m+q) {
        cin >> a[i] >> b[i] >> c[i];
        edge.push_back({c[i], a[i], b[i], i});
    }

    sort(edge.begin(), edge.end());

    UnionFind uf(n+1);
    vector<bool> used(m+q);
    rep(i, 0, m+q){
        if(uf.same(edge[i][1], edge[i][2])) continue;
        if(edge[i][3] > m-1) used[edge[i][3]] = true;
        else uf.unite(edge[i][1], edge[i][2]);
    }

    rep(i, 0, q){
        if(used[m+i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    

    
    return 0;
}