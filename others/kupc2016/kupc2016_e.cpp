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
// https://atcoder.jp/contests/kupc2016/tasks/kupc2016_e

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

template <class T> 
struct FordFulkerson{
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
    vector<bool> used; // 頂点が探索済みであるかをチェックするリスト
    vector<vector<Edge>> graph; // 残余グラフの隣接表現リスト
public:
    FordFulkerson(int n_) : n(n_) {
        used.resize(n);
        graph.resize(n);
    }

    // 頂点fromからtoに向かう、上限 cost リットル/秒の辺を追加
    void add_edge(int from, int to, T cost){
        int size_from = (int)graph[from].size(); // 現時点でのG[from]の要素数
        int size_to = (int)graph[to].size(); // 現時点でのG[to]の要素数
        graph[from].push_back(Edge{to, cost, size_to});
        graph[to].push_back(Edge{from, 0, size_from});
    }

    // 深さ優先探索(Fはスタートからposに到達するパスで流せる流量の最大値)
    // 返り値は流したフローの量(流せない場合は0を返す)
    T dfs(int pos, int goal, T F) {
        // ゴールに到着：フローを流せる
        if(pos == goal) return F;  

        used[pos] = true;  // posを探索済みとする

        // 探索する
        rep(i, 0, (int)graph[pos].size()) {
            // 容量0ならば流さない
            if(graph[pos][i].cap == 0) continue;
            // すでに探索済みの頂点にも流さない
            if(used[graph[pos][i].to] == true) continue;
            // 目的地までのパスを探す
            T flow = dfs(graph[pos][i].to, goal, min(F, graph[pos][i].cap));

            // フローを流せる場合、残余グラフの容量を flow だけ増減させる
            if(flow > 0) {
                graph[pos][i].cap -= flow;
                graph[graph[pos][i].to][graph[pos][i].rev].cap += flow;
                return flow;
            }
        }

        // 全ての辺を探索しても見つからなかった場合は0を返す
        return 0;
    }

    // 頂点 s から頂点 t までの最大フローの総流量を返す
    T max_flow(int s, int t) {
        T total_flow = 0;
        while(true) {
            rep(i, 0, n) used[i] = false;
            T F = dfs(s, t, 1e9);

            // フローを流せなくなったら操作終了
            if(F == 0) break;
            total_flow += F;
        }
        return total_flow;
    }
};


int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    auto id = [&](int i, int j, int k){
        return 2*(i*w+j)+k+1;
    };
    if(h == 1 || w == 1){
        int cnt = 0;
        rep(i, 0, h){
            rep(j, 0, w){
                if(s[i][j] == 'X') cnt++;
            }
        }
        if(cnt) cout << 0 << endl;
        else cout << -1 << endl;
        return 0;
    }
    
    FordFulkerson<int> mf(2*h*w+2);
    bool f = false;
    rep(i, 0, w){
        if(s[0][i] == 'X') f = true;
        if(s[h-1][i] == 'X') f = true;
        mf.add_edge(id(0, i, 1), 2*h*w+1, 1);
        mf.add_edge(id(h-1, i, 1), 2*h*w+1, 1);
    }
    rep(i, 0, h){
        if(s[i][0] == 'X') f = true;
        if(s[i][w-1] == 'X') f = true;
        mf.add_edge(id(i, 0, 1), 2*h*w+1, 1);
        mf.add_edge(id(i, w-1, 1), 2*h*w+1, 1);
    }
    if(f){
        cout << -1 << endl;
        return 0;
    }

    rep(i, 0, h){
        rep(j, 0, w){
            if(s[i][j] == 'X'){
                mf.add_edge(0, id(i, j, 1), h*w);
            }else{
                mf.add_edge(id(i, j, 0), id(i, j, 1), 1);
            }
            rep(k, 0, 4){
                int ni = i+(k-1)%2, nj = j+(k-2)%2;
                if(ni < 0 || h-1 < ni || nj < 0 || w-1 < nj) continue;
                mf.add_edge(id(i, j, 1), id(ni, nj, 0), 1);
            }
        }
    }

    cout << mf.max_flow(0, 2*h*w+1) << endl;


    
    return 0;
}