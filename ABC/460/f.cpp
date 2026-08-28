#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

template<typename T> 
struct LCA {
    int n, root, lg;
    vector<vector<int>> to;
    vector<vector<T>> cost;
    vector<int> depth;
    vector<T> cost_to_root;
    vector<vector<int>> par;
    
    LCA(int _n): n(_n), to(_n), cost(_n), depth(_n), cost_to_root(_n) {
        lg = 0; // ダブリングで 2^lg まで持つ
        while((1<<lg) < n) lg++;
        par = vector<vector<int>>(n+1, vector<int>(lg, n));
    }
    
    void add_edge(int u, int v, T c=1){
        to[u].push_back(v), cost[u].push_back(c);
        to[v].push_back(u), cost[v].push_back(c);
    }

    void dfs(int pos, int dep=0, T c=0, int pre=-1){
        if(pre != -1) par[pos][0] = pre;
        depth[pos] = dep;
        cost_to_root[pos] = c;
        for(int i = 0; i < (int)to[pos].size(); i++){
            int nxt = to[pos][i];
            if(nxt == pre) continue;
            dfs(nxt, dep+1, c+cost[pos][i], pos);
        }
    }

    // 各頂点の 2^i (0 <= i <= lg) 個上の頂点をダブリングで求める
    void build(int _root=0){
        root = _root;
        dfs(root);
        for(int i = 0; i < lg-1; i++){
            for(int v = 0; v < n; v++){
                par[v][i+1] = par[par[v][i]][i];
            }
        }
    }

    // LCA
    int lca(int u, int v){
        if(depth[u] > depth[v]) swap(u, v);
        int gap = depth[v]-depth[u];
        
        // 深い方 (v) を浅い方 (u) と同じ深さまで移動した頂点にする
        for(int i = lg-1; i >= 0; i--){
            int len = 1<<i;
            if(gap >= len){
                gap -= len;
                v = par[v][i];
            }
        }

        if(u == v) return u; // 同じ頂点なら u が LCA
        
        // LCAの1つ下まで登る
        for(int i = lg-1; i >= 0; i--){
            int nu = par[u][i], nv = par[v][i];
            if(nu != nv) u = nu, v = nv;
        }
        return par[u][0];
    }
    int operator()(int u, int v){
        return lca(u, v);
    }

    // 辺の本数
    int length(int u, int v){
        int w = lca(u, v);
        return depth[u]+depth[v]-depth[w]*2;
    }
    // 重み付き距離
    T dist(int u, int v){
        int w = lca(u, v);
        return cost_to_root[u]+cost_to_root[v]-cost_to_root[w]*2;
    }
};
LCA<int> lca(100005);

struct S {
    int a, b;
    int d;
};
S op(S a, S b){
    if(a.d == -1) return b;
    if(b.d == -1) return a;
    S c = a;
    if(c.d < b.d) c = b;
    if(c.d < lca.dist(a.a, b.a)){
        c.d = lca.dist(a.a, b.a);
        c.a = a.a;
        c.b = b.a;
    }
    if(c.d < lca.dist(a.a, b.b)){
        c.d = lca.dist(a.a, b.b);
        c.a = a.a;
        c.b = b.b;
    }
    if(c.d < lca.dist(a.b, b.a)){
        c.d = lca.dist(a.b, b.a);
        c.a = a.b;
        c.b = b.a;
    }
    if(c.d < lca.dist(a.b, b.b)){
        c.d = lca.dist(a.b, b.b);
        c.a = a.b;
        c.b = b.b;
    }
    return c;
};

S e(){
    return S(-1, -1, -1);
};

int main(){
    int n; cin >> n;
    rep(i, 0, n-1){
        int u, v; cin >> u >> v; u--, v--;
        lca.add_edge(u, v);
    }
    lca.build();


    vector<S> init(n);
    rep(i, 0, n) init[i] = S(i, i, 0);
    segtree<S, op, e> seg(init);
    vector<int> col(n, 1);
    int q; cin >> q;
    while(q--){
        int x; cin >> x; x--;
        col[x] = 1-col[x];
        if(col[x] == 1){
            seg.set(x, S(x, x, 0));
        }else{
            seg.set(x, S(-1, -1, -1));
        }
        cout << seg.all_prod().d << endl;
    }



    return 0;
}