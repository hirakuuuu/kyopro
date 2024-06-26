#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const ll INF = (1LL<<60);

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
lowest common ancestor(LCA)とは、根付き木の2つの頂点に対して、
共通祖先(common ancestor)のうち最も深さが深い頂点のこと、またそれを求める問題のことである。 
最小共通祖先, 最小共通先祖, nearest common ancestor, NCA, 最近共通祖先 などとも呼ばれる。

求め方はいくつかあるが、「オイラーツアー」と「区間minセグメント木」を用いた解法を採用。

-それぞれが eular_tour 上ではじめて現れるindex pa,pbを取得する。(pa<pbと仮定する)
- euler_tour上で、区間[pa,pb]内から、depthが最小となる頂点を取得する
- そいつがLCAである（このような頂点はただ1つ存在する）

参考: https://yukicoder.me/wiki/lowest_common_ancestor
      https://ikatakos.com/pot/programming_algorithm/graph_theory/lowest_common_ancestor
      https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
*/

// ここから
template<typename T> class segtree {
private:
    int n,sz;
    vector<pair<T, int> > node;
public:
    void resize(const vector<T>& v){
        sz = (int)v.size();
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.resize(2*n);
        for(int i = 0; i < sz; i++){
            node[i+n] = make_pair(v[i], i);
        }
        for(int i=n-1; i>=1; i--){
            node[i] = min(node[2*i], node[2*i+1]);
        }
    }
    pair<T, int> query(int a,int b)
    {
        pair<T, int> res1 = make_pair(numeric_limits<T>::max(), -1);
        pair<T, int> res2 = make_pair(numeric_limits<T>::max(), -1);
        a += n, b += n;
        while(a != b){
            if(a % 2) res1 = min(res1, node[a++]);
            if(b % 2) res2 = min(res2, node[--b]);
            a >>= 1, b >>= 1;
        }
        return min(res1, res2);
    }
};
 
class LCA{
private:
    int V;
    vector<vector<int> > G;
    vector<int> ord,depth,id;
    segtree<int> st;
    void dfs(int u,int p,int k){
        id[u] = (int)ord.size();
        ord.push_back(u);
        depth[u] = k;
        for(int v : G[u]){
            if(v != p){
                dfs(v,u,k+1);
                ord.push_back(u);
            }
        }
    }
 
public:
    LCA(int node_size) : V(node_size), G(V), depth(V), id(V, -1){}
    LCA(vector<vector<int>> g) : V((int)g.size()), G(g), depth((int)g.size()), id((int)g.size(), -1){}

    void add_edge(int from,int to){
        G[from].push_back(to),G[to].push_back(from);
    }
    void build(){
        ord.reserve(2*V-2);
        for(int i = 0; i < V; i++){
            if(id[i] < 0){
                dfs(i,-1,0);
            }
        }
        vector<int> stvec(2*V-2);
    	for(int i = 0; i < 2*V-2; i++){
    		stvec[i] = depth[ord[i]];
    	}
        st.resize(stvec);
    }
    int lca(int u,int v){
        return ord[st.query(min(id[u],id[v]),max(id[u],id[v])+1).second];
    }
    int dist(int u,int v){
        int lca_ = lca(u,v);
        return depth[u] + depth[v] - 2*depth[lca_];
    }
};
// ここまで

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n){
        int k; cin >> k;
        rep(j, 0, k){
            int c; cin >> c;
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }

    LCA lca(g);
    lca.build();

    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << lca.lca(u, v) << endl;
    }

    
    return 0;
}