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

class MaximumFlow {
public:
    int size_ = 0;
    bool used[409];
    vector<Edge> G[409];

    // 頂点数 N の残余グラフを準備
    void init(int N) {
        size_ = N;
        rep(i, 0, size_+1) G[i].clear();
    }

    // 頂点 a から b に向かう、上限 c リットル/秒の辺を追加
    void add_edge(int a, int b, int c) {
        int Current_Ga = G[a].size(); // 現時点でのG[a]の要素数
        int Current_Gb = G[b].size(); // 現時点でのG[b]の要素数
        G[a].push_back(Edge{b, c, Current_Gb});
        G[b].push_back(Edge{a, 0, Current_Ga});
    }

    // 深さ優先探索(Fはスタートからposに到達する過程での"残余グラフの辺の容量"の最小値)
    // 返り値は流したフローの量(流せない場合は0を返す)
    int dfs(int pos, int goal, int F) {
        // ゴールに到着：フローを流せる
        if(pos == goal) return F;
        used[pos] = true;

        // 探索する
        rep(i, 0, G[pos].size()) {
            // 容量0の辺は使えない
            if(G[pos][i].cap == 0) continue;

            // すでに訪問した頂点に行っても意味が無い
            if(used[G[pos][i].to] == true) continue;

            // 目的地までのパスを探す
            int flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));

            // フローを流せる場合、残余グラフの容量を flow だけ増減させる
            if(flow >= 1) {
                G[pos][i].cap -= flow;
                G[G[pos][i].to][G[pos][i].rev].cap += flow;
                return flow;
            }
        }

        // 全ての辺を探索しても見つからなかった場合は0を返す
        return 0;
    }

    // 頂点 s から頂点 t までの最大フローの総流量を返す
    int max_flow(int s, int t) {
        int Total_Flow = 0;
        while(true) {
            rep(i, 0, size_+1) used[i] = false;
            int F = dfs(s, t, 1e9);

            // フローを流せなくなったら操作終了
            if(F == 0) break;
            Total_Flow += F;
        }
        return Total_Flow;
    }
};

int main(){
    
    return 0;
}