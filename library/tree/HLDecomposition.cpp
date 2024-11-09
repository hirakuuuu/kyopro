#include <bits/stdc++.h>
using namespace std;
#define ll long long


template<typename T>
struct HLDecomposition{
    int n, root;
    vector<vector<int>> to;
    vector<int> par;   // 根付き木の親
    vector<int> subsz; // 部分木のサイズ
    vector<int> in;    // 行きがけ順
    vector<int> head;  // 最も近い heavy なパス上の点

    HLDecomposition(int _n): n(_n), to(_n), par(_n), subsz(_n), in(_n), head(_n) {}

    void add_edge(int u, int v){
        to[u].push_back(v);
        to[v].push_back(u);
    }

    // 部分木のサイズを計算 and heavy な辺を to[v][0] に移動
    void dfs1(int pos, int pre){
        par[pos] = pre;
        subsz[pos] = 1;
        // heavy な辺を先頭に持っていく
        if(to[pos].size() && to[pos][0] == pre) swap(to[pos][0], to[pos].back());
        for(int i = 0; i < (int)to[pos].size(); i++){
            int nxt = to[pos][i];
            if(nxt == pre) continue;
            dfs1(nxt, pos);
            subsz[pos] += subsz[nxt];
            if(subsz[to[pos][0]] < subsz[nxt]) swap(to[pos][0], to[pos][i]);
        }
    }

    void dfs2(int pos, int pre, int &t){
        in[pos] = t++;
        for(auto nxt: to[pos]){
            if(nxt == pre) continue;
            head[nxt] = (to[pos][0] == nxt ? head[pos] : nxt);
            dfs2(nxt, pos, t);
        }
    }

    void init(int _root=0){
        root = _root;
        dfs1(root, -1);
        int t = 0;
        dfs2(root, -1, t);
    }

    // u-v パスの間にある辺に対応する列状の区間の集合 [l, r)
    // HLDにより個の個数が O(log n) に抑えられる
    vector<pair<int, int>> get_edge(int u, int v){
        vector<pair<int, int>> res;
        while(true){
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            res.emplace_back(in[head[v]], in[v]+1);
            v = par[head[v]];
        }
        if(in[u]+1 != in[v]+1) res.emplace_back(in[u]+1, in[v]+1);
        return res;
    }

    // u-v パスの間にある頂点に対応する列状の区間の集合 [l, r)
    // HLDにより個の個数が O(log n) に抑えられる
    vector<pair<int, int>> get_vertex(int u, int v){
        vector<pair<int, int>> res;
        while(true){
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            res.emplace_back(in[head[v]], in[v]+1);
            v = par[head[v]];
        }
        res.emplace_back(in[u], in[v]+1);
        return res;
    }
};

int main(){
    return 0;
}