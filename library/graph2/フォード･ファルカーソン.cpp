#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 最大フロー問題を解くためのアルゴリズム
struct Edge {
    // to: 残余グラフ上での辺の行き先
    // cap: 残余グラフ上での辺の容量
    // rev: 辺 u → G[u][i].to の逆辺 G[u][i].to → u が G[G[u][i].to] の何番目に存在するか
    // これらの情報があると残余グラフの辺の容量の変更が楽になる
    int to, cap, rev;
};

struct MaximumFlow{
private:
    int n; // 頂点数
    vector<bool> used; // 頂点が探索済みであるかをチェックするリスト
    vector<vector<Edge>> graph; // 残余グラフの隣接表現リスト

public:
    // コンストラクタ
    MaximumFlow(int n_) : n(n_) {
        used.resize(n);
        graph.resize(n);
    }

    // 頂点fromからtoに向かう、上限 cost リットル/秒の辺を追加
    void add_edge(int from, int to, int cost){
        int size_from = (int)graph[from].size(); // 現時点でのG[from]の要素数
        int size_to = (int)graph[to].size(); // 現時点でのG[to]の要素数
        graph[from].push_back(Edge{to, cost, size_to});
        graph[to].push_back(Edge{from, 0, size_from});
    }

    // 深さ優先探索(Fはスタートからposに到達するパスで流せる流量の最大値)
    // 返り値は流したフローの量(流せない場合は0を返す)
    int dfs(int pos, int goal, int F) {
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
            int flow = dfs(graph[pos][i].to, goal, min(F, graph[pos][i].cap));

            // フローを流せる場合、残余グラフの容量を flow だけ増減させる
            if(flow >= 1) {
                graph[pos][i].cap -= flow;
                graph[graph[pos][i].to][graph[pos][i].rev].cap += flow;
                return flow;
            }
        }

        // 全ての辺を探索しても見つからなかった場合は0を返す
        return 0;
    }

    // 頂点 s から頂点 t までの最大フローの総流量を返す
    int max_flow(int s, int t) {
        int total_flow = 0;
        while(true) {
            rep(i, 0, n) used[i] = false;
            int F = dfs(s, t, 1e9);

            // フローを流せなくなったら操作終了
            if(F == 0) break;
            total_flow += F;
        }
        return total_flow;
    }
};


int main(){
    
    return 0;
}