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

// 問題
// https://atcoder.jp/contests/abc065/tasks/arc076_b

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
    int n; cin >> n;
    vector<vector<int>> xy(n), yx(n);
    rep(i, 0, n){
        int x, y; cin >> x >> y;
        xy[i] = {x, y, i};
        yx[i] = {y, x, i};
    }

    sort(xy.begin(), xy.end());
    sort(yx.begin(), yx.end());
    vector<vector<int>> edge;
    rep(i, 1, n){
        edge.push_back({min(abs(xy[i-1][0]-xy[i][0]), abs(xy[i-1][1]-xy[i][1])), xy[i-1][2], xy[i][2]});
        edge.push_back({min(abs(yx[i-1][0]-yx[i][0]), abs(yx[i-1][1]-yx[i][1])), yx[i-1][2], yx[i][2]});
    }

    sort(edge.begin(), edge.end());
    UnionFind uf(n);
    ll ans = 0;
    rep(i, 0, 2*n-2){
        if(uf.same(edge[i][1], edge[i][2])) continue;
        ans += edge[i][0];
        uf.unite(edge[i][1], edge[i][2]);
    }

    cout << ans << endl;
    
    return 0;
}