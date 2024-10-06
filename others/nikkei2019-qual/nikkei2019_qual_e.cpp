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
    vector<ll> w; // 頂点の重み
    inline ll root(ll n){
        return (parent[n] < 0? n:parent[n] = root(parent[n]));
    }
public:
    UnionFind(ll n_, vector<ll> x_): parent(n_, -1), maxi(n_), mini(n_), w(x_){
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
        maxi[rx] = std::max(maxi[rx], maxi[ry]); // UFのメソッドの方と被らないように名前空間を指定する
        mini[rx] = std::min(mini[rx], mini[ry]);
        w[rx] += w[ry];
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

    inline ll weight(ll x){
        return w[root(x)];
    }

    void clear(){
        rep(i, 0, (ll)parent.size()){
            parent[i] = -1;
        }
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
};

/*
最終的に各連結成分で最大の重みの辺について条件を満たしていればよい
重み y の辺がそれになりうる必要条件は、その重み以下の辺のみをたどっていける頂点の重みの総和が y 以下であること
これは UF で辺の重みの昇順に追加していく過程で調べられる
そのあと、辺の重みの降順に、残すかどうかを調べる
- 残すことが確定しているならOK
- 残すことが確定しておらず、上で最大の重み候補とチェックされた場合、そこからＤＦＳでその重み以下の辺をすべて残すとする
- そうでない場合は、残せない

*/

int main(){
    int n, m; cin >> n >> m;
    vector<ll> x(n);
    rep(i, 0, n) cin >> x[i];
    vector<tuple<ll, int, int, int>> e(m);
    vector<vector<tuple<ll, int, int>>> g(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b; a--, b--;
        ll y; cin >> y;
        e[i] = {y, a, b, i};
        g[a].push_back({y, b, i});
        g[b].push_back({y, a, i});
    }

    UnionFind uf(n, x);

    sort(e.begin(), e.end());
    vector<bool> check(m);
    rep(i, 0, m){
        auto [y, a, b, e_id] = e[i];
        uf.unite(a, b);
        if(y <= uf.weight(a)){
            check[e_id] = true;
        }
    }

    vector<bool> used(m);
    auto dfs = [&](auto self, int pos, int pre, ll max_y) -> void {
        for(auto [y, nxt, e_id]: g[pos]){
            if(nxt == pre) continue;
            if(used[e_id]) continue;
            if(y > max_y) continue;
            used[e_id] = true;
            self(self, nxt, pos, max_y);
        }
    };
    rrep(i, m-1, 0){
        auto [y, a, b, e_id] = e[i];
        if(used[e_id]) continue;
        if(!check[e_id]) continue;
        // y 以下の辺のみをたどってたどり着ける辺を used にする
        dfs(dfs, a, -1, y);
    }
    int ans = 0;
    rep(i, 0, m) ans += 1-used[i];
    cout << ans << endl;

    
    return 0;
}