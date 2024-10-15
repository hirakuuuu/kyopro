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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
Lowlink
- グラフの関節点、橋を求めるためのアルゴリズム
- 二重頂点連結成分分解に応用できる
*/

class Lowlink {
    struct Edge {
        int to, id;
        Edge() {};
        Edge(int _to, int _id=-1): to(_to), id(_id) {}
    };

public:
    int n, m;
    vector<vector<Edge>> g;
    vector<pair<int, int>> edges;
    Lowlink(int _n): n(_n), m(0), g(n) {};
    
    void add_edge(int a, int b){
        if(a > b) swap(a, b);
        edges.emplace_back(a, b);
        g[a].emplace_back(b, m);    // {端点、id}
        g[b].emplace_back(a, m++);
    }

    vector<int> is_root; // DFSで根であるかどうか
    vector<vector<int>> dfs_tree; // DFS木
    vector<int> ord; // 行きがけ順
    vector<int> low; // DFS木上で後退辺を１つたどっていける ord の最小値
    vector<int> par; // DFS木の親（根は -1）
    // low を求める
    void init(){
        is_root = vector<int>(n);
        dfs_tree = vector<vector<int>>(n);
        ord = low = par = vector<int>(n, -1);
        int k = 0;
        auto dfs = [&](auto self, int pos, int eid=-1) -> int {
            low[pos] = ord[pos] = k++;
            for(auto e: g[pos]) if(e.id != eid){
                if(ord[e.to] == -1){ // DFS 木の辺
                    par[e.to] = pos;
                    dfs_tree[pos].emplace_back(e.to);
                    low[pos] = min(low[pos], self(self, e.to, e.id));
                }else if(ord[e.to] < ord[pos]){ // 後退辺
                    low[pos] = min(low[pos], ord[e.to]);
                }
            }
            return low[pos];
        };
        for(int v = 0; v < n; v++){
            if(ord[v] == -1){ is_root[v] = 1; dfs(dfs, v); }
        }
    }

    // 関節点
    vector<int> aps; // 関節点
    void build_aps(){
        for(int u = 0; u < n; u++){
            if(is_root[u]){
                // 根の場合、子が２つ以上存在すると関節点
                if(dfs_tree[u].size() >= 2) aps.emplace_back(u);
            }else{
                // 根でない場合、子 v で ord[u] <= low[v] を満たすものが存在する
                bool f = false;
                for(auto v: dfs_tree[u]){
                    if(ord[u] <= low[v]) f = true;
                }
                if(f) aps.emplace_back(u);
            }
        }
    }


    // 橋
    vector<int> bridge; // 橋である辺の index , 取得したいときは edges[ind] ととる
    void build_bridge(){
        for(int i = 0; i < m; i++){
            auto [u, v] = edges[i];
            if(ord[u] > ord[v]) swap(u, v); // 根に近い方を u とする
            if(ord[u] < low[v]) bridge.push_back(i); // 後退辺を1本たどって、u より上に行けない
        }
    }

    // 二重頂点連結成分分解
    vector<vector<int>> bc; // 各成分ごとの辺のID
    vector<int> bc_id;      // 各辺がどの成分に属するか
    void bcc(){ // Bi-Connected-Components
        bc_id = vector<int>(m, -1);
        auto add = [&](int eid, int k) -> void {
            bc[k].push_back(eid);
            bc_id[eid] = k;
        };
        auto dfs = [&](auto self, int pos, int k=-1) -> void {
            for(auto e: g[pos]) if(e.to != par[pos]){
                if(par[e.to] == pos){ // DFS木上の辺
                    int nk = k;
                    if(low[e.to] >= ord[pos]){ // e が橋になっている
                        nk = (int)bc.size(), bc.emplace_back();
                    }
                    add(e.id, nk);
                    self(self, e.to, nk);
                }else if(ord[e.to] < ord[pos]){
                    add(e.id, k);
                }
            }
        };
        rep(v, 0, n) if(par[v] == -1) dfs(dfs, v);
    }
};


// 関節点

// verify: https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A
int main(){
    int n, m; cin >> n >> m;
    Lowlink g(n);
    rep(i, 0, m){
        int s, t; cin >> s >> t;
        g.add_edge(s, t);
    }
    g.init();
    g.build_aps();
    for(auto ap: g.aps){
        cout << ap << endl;
    }

    return 0;
}