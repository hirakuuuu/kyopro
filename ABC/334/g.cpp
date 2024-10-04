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
using mint = modint998244353;
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
    
    void addEdge(int a, int b){
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
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    int n = 0;
    vector<vector<int>> id(h, vector<int>(w, -1));
    rep(i, 0, h) rep(j, 0, w){
        if(s[i][j] == '#'){
            id[i][j] = n++;
        }
    }
    Lowlink g(n);
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] != '#') continue;
            rep(k, 2, 4){
                int ni = i+(k-1)%2, nj = j+(k-2)%2;
                if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                if(s[ni][nj] != '#') continue;
                g.addEdge(id[i][j], id[ni][nj]);
            }
        }
    }
    g.init();
    g.bcc();

    int comp = 0;
    rep(v, 0, n) if(g.par[v] == -1) comp++;
    mint ans = mint(comp)*n;
    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] != '#') continue;
            set<int> st;
            for(auto e: g.g[id[i][j]]){
                st.insert(g.bc_id[e.id]);
            }
            ans += (int)st.size()-1;
        }
    }
    ans /= n;
    cout << ans.val() << endl;
    return 0;
}