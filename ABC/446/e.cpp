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
    int m, a, b; cin >> m >> a >> b;
    vector<vector<int>> g(m*m);
    rep(x, 0, m){
        rep(y, 0, m){
            // (x, y) -> (y, a*y+b*z);
            int nx = y, ny = (a*y+b*x)%m;
            g[nx*m+ny].push_back(x*m+y);
            // cout << x << ' ' << y << ' ' << nx << ' ' << ny << endl;
        }
    }
    vector<int> seen(m*m);
    queue<int> que;
    rep(x, 0, m){
        que.push(x);
        seen[x] = 1;
        if(x > 0){
            que.push(x*m);
            seen[x*m] = 1;
        }
    }

    UnionFind uf(m*m);
    while(!que.empty()){
        auto q = que.front(); que.pop();
        for(auto nq: g[q]){
            if(seen[nq]) continue;
            uf.unite(q, nq);
            seen[nq] = 1;
            que.push(nq);
        }
    }

    int ans = m*m;
    set<int> s;
    rep(x, 0, m){
        s.insert(uf[x*m]);
        s.insert(uf[x]);
    }
    for(auto r: s){
        ans -= uf.size(r);
    }
    cout << ans << endl;
    return 0;
}