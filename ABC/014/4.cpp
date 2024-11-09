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

template<typename T> 
struct LCA {
    int n, root, lg;
    vector<vector<int>> g;
    vector<vector<T>> cost;
    vector<int> depth;
    vector<T> cost_to_root;
    vector<vector<int>> par;
    
    LCA(int _n): n(_n), g(_n), cost(_n), depth(_n), cost_to_root(_n) {
        lg = 0; // ダブリングで 2^lg まで持つ
        while((1<<lg) < n) lg++;
        par = vector<vector<int>>(n+1, vector<int>(lg, n));
    }
    
    void add_edge(int u, int v, T c=1){
        g[u].push_back(v), cost[u].push_back(c);
        g[v].push_back(u), cost[v].push_back(c);
    }

    void dfs(int pos, int dep=0, T c=0, int pre=-1){
        if(pre != -1) par[pos][0] = pre;
        depth[pos] = dep;
        cost_to_root[pos] = c;
        for(int i = 0; i < (int)g[pos].size(); i++){
            int nxt = g[pos][i];
            if(nxt == pre) continue;
            dfs(nxt, dep+1, c+cost[pos][i], pos);
        }
    }

    // 各頂点の 2^i (0 <= i <= lg) 個上の頂点をダブリングで求める
    void init(int _root=0){
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

int main(){
    int n; cin >> n;
    LCA<int> lca(n);
    rep(i, 0, n-1){
        int x, y; cin >> x >> y; x--, y--;
        lca.add_edge(x, y);
    }
    lca.init();

    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b; a--, b--;
        cout << lca.dist(a, b)+1 << endl;
    }
    
    return 0;
}