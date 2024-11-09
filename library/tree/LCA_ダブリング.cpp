#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

// verify: https://atcoder.jp/contests/abc014/tasks/abc014_4
int main(){
    int n; cin >> n;
    LCA<int> lca(n);
    for(int i = 0; i < n-1; i++){
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