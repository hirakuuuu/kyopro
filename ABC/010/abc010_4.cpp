#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc289/tasks/abc289_f

template <class T> 
struct Dinic{
private:
    struct Edge {
        // to: 残余グラフ上での辺の行き先
        // cap: 残余グラフ上での辺の容量
        // rev: 辺 u → G[u][i].to の逆辺 G[u][i].to → u が G[G[u][i].to] の何番目に存在するか
        // これらの情報があると残余グラフの辺の容量の変更が楽になる
        int to;
        T cap;
        int rev;
    };
    int n; // 頂点数
    vector<vector<Edge>> graph; // 残余グラフの隣接表現リスト
    vector<int> level; // ｓからの距離（BFSで求める）
    vector<int> iter; // どこまで探索済みか
    T inf = 1e9;

public:
    Dinic(int n_) : n(n_) {
        graph.resize(n);
        level.resize(n);
        iter.resize(n);
    }

    // 頂点fromからtoに向かう、上限 cap リットル/秒の辺を追加
    void add_edge(int from, int to, T cap){
        int size_from = (int)graph[from].size(); // 現時点でのG[from]の要素数
        int size_to = (int)graph[to].size(); // 現時点でのG[to]の要素数
        graph[from].push_back(Edge{to, cap, size_to});
        graph[to].push_back(Edge{from, 0, size_from});
    }

    // sからの最短距離をBFSで計算する
    void bfs(int s){
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int i = 0; i < (int)graph[v].size(); i++){
                Edge &e = graph[v][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v]+1;
                    que.push(e.to);
                }
            }
        }
    }

    // 深さ優先探索(Fはスタートからposに到達するパスで流せる流量の最大値)
    // 返り値は流したフローの量(流せない場合は0を返す)
    T dfs(int v, int t, T f) {
        // ゴールに到着：フローを流せる
        if(v == t) return f;  
        // 探索する
        for(int &i = iter[v]; i < (int)graph[v].size(); i++) {
            Edge &e = graph[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                T d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        // 全ての辺を探索しても見つからなかった場合は0を返す
        return 0;
    }

    // 頂点 s から頂点 t までの最大フローの総流量を返す
    T max_flow(int s, int t) {
        T flow = 0;
        while(true) {
            bfs(s);
            if(level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            T f = dfs(s, t, inf);
            // フローを流せなくなったら操作終了
            if(f == 0) break;
            flow += f;
        }
        return flow;
    }
};


int main(){
    int n, g, e; cin >> n >> g >> e;
    Dinic<int> mf(n+1);
    rep(i, 0, g){
        int p; cin >> p;
        mf.add_edge(p, n, 1);
    }
    rep(i, 0, e){
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        mf.add_edge(a, b, 1);
        mf.add_edge(b, a, 1);
    }

    cout << mf.max_flow(0, n) << endl;
    return 0;
}