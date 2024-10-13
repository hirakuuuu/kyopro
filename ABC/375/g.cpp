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


// sを始点とする各頂点への距離の最小値を格納した配列を返す
vector<ll> dijk(int s, vector<vector<pair<ll, ll>>> &g){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    vector<ll> dist(g.size(), INF);
    que.push(make_pair(0, s));
    dist[s] = 0;
    while(!que.empty()){
        pair<ll, ll> q = que.top(); que.pop();
        ll d = q.first, u = q.second;
        if(dist[u] < d) continue;
        for(auto nq: g[u]){
            ll v = nq.first, cost = nq.second;
            if(dist[v] > d+cost){
                dist[v] = d+cost;
                que.push({dist[v], v});
            }
        }
    }
    return dist;
}

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

    vector<int> ord; // 行きがけ順
    vector<int> low; // DFS木上で後退辺を１つたどっていける ord の最小値
    vector<int> par; // DFS木の親（根は -1）
    // low を求める
    void init(){
        ord = low = par = vector<int>(n, -1);
        int k = 0;
        auto dfs = [&](auto self, int pos, int eid=-1) -> int {
            low[pos] = ord[pos] = k++;
            for(auto e: g[pos]) if(e.id != eid){
                if(ord[e.to] == -1){
                    par[e.to] = pos;
                    low[pos] = min(low[pos], self(self, e.to, e.id));
                }else if(ord[e.to] < ord[pos]){ // 後退辺
                    low[pos] = min(low[pos], ord[e.to]);
                }
            }
            return low[pos];
        };
        rep(v, 0, n) if(ord[v] == -1) dfs(dfs, v);
    }

    // 関節点

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


int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    vector<ll> c(m);
    map<pair<int, int>, int> edge_id;
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, 0, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        g[a[i]].push_back({b[i], c[i]});
        g[b[i]].push_back({a[i], c[i]});
        edge_id[{a[i], b[i]}] = edge_id[{b[i], a[i]}] = i;
    }
    vector<ll> dist_1 = dijk(0, g);
    vector<ll> dist_n = dijk(n-1, g);

    vector<int> ans(m);
    vector<int> nodes;
    rep(i, 0, m){
        if(dist_1[n-1] == min(dist_1[a[i]]+dist_n[b[i]], dist_1[b[i]]+dist_n[a[i]])+c[i]){
            nodes.push_back(a[i]);
            nodes.push_back(b[i]);
        }
    }
    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    vector<int> node_id(n, -1);
    rep(i, 0, (int)nodes.size()){
        node_id[nodes[i]] = i;
    }

    Lowlink ng(nodes.size());
    rep(i, 0, m){
        if(dist_1[n-1] == min(dist_1[a[i]]+dist_n[b[i]], dist_1[b[i]]+dist_n[a[i]])+c[i]){
            // cout << node_id[a[i]] << ' ' << node_id[b[i]] << endl;
            ng.add_edge(node_id[a[i]], node_id[b[i]]);
        }
    }
    ng.init();
    ng.build_bridge();
    vector<int> is_bridge(ng.edges.size());
    for(auto id: ng.bridge) is_bridge[id] = 1;
    rep(i, 0, ng.edges.size()){
        if(is_bridge[i]){
            auto [u, v] = ng.edges[i];
            u = nodes[u], v = nodes[v];
            // cout << u << ' ' << v << endl;
            ans[edge_id[{u, v}]] = 1;
        }
    }
    rep(i, 0, m){
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}