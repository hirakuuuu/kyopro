#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

/*
クエリごとにDFS、根をｖに含まれる適当な頂点とする
各頂点について、子孫にｖに含まれる頂点があれば、その頂点に到達する時に通った辺は必要

木の巡回を考えると、DFSの行きがけ順にソートすることで、Σ (根からv[i]の距離)-(根からv[i]と v[i+1]のLCAの距離)と計算できる
LCAの求め方にもダブリングが現れる
*/


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
    int preorder(int u){
        return id[u];
    }
};


int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    LCA lca(g);
    lca.build();

    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        vector<int> v(k);
        rep(i, 0, k){
            cin >> v[i];
            v[i]--;
        }
        sort(v.begin(), v.end(), [&](int i, int j){
            return lca.preorder(i) < lca.preorder(j);
        });
        ll ans = 0;
        rep(i, 0, k){
            ans += lca.dist(v[i], v[(i+1)%k]);
        }
        cout << ans/2 << endl;
    }

    
    return 0;
}