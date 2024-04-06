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
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

struct Edge {
    ll to, cap, cost, rev;
};

struct MinCostFlow {
private:
    ll n; // 頂点数
    vector<vector<Edge>> graph; // 残余グラフの隣接表現リスト
    vector<ll> h; // ポテンシャル
    vector<ll> dist; // 最短距離
    vector<ll> prevv, preve; // 直前の頂点と辺

public:
    // コンストラクタ
    MinCostFlow(ll n_): n(n_) {
        graph.resize(n);
        h.resize(n);
        dist.resize(n);
        prevv.resize(n);
        preve.resize(n);
    }

    // 辺の追加
    void add_edge(ll from, ll to, ll cap, ll cost){
        ll size_from = (ll)graph[from].size(); // 現時点でのG[from]の要素数
        ll size_to = (ll)graph[to].size(); // 現時点でのG[to]の要素数
        graph[from].push_back((Edge){to, cap, cost, size_to});
        graph[to].push_back((Edge){from, 0, -cost, size_from});
    }

    // sからtへの流量fの最小費用流を求める
    // 流せない場合は-1を返す
    ll min_cost_flow(ll s, ll t, ll f) {
        ll res = 0;
        fill(h.begin(), h.end(), 0); // ポテンシャルを初期化

        while(f > 0) {
            // ダイクストラ法を用いてhを更新する
            priority_queue<pii, vector<pii>, greater<pii>> que;
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            que.push({0, s});

            while(!que.empty()){
                pii q = que.top(); que.pop();
                ll v = q.second;
                if(dist[v] < q.first) continue;

                rep(i, 0, (ll)graph[v].size()){
                    Edge e = graph[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]) {
                        dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push({dist[e.to], e.to});
                    }
                }
            }
            if(dist[t] == INF) {
                // これ以上流せない
                return -1;
            }
            // ポテンシャルの更新
            rep(i, 0, n){
                // ポテンシャルを除いた最短路に更新する
                h[i] = dist[i]+h[i]-h[s];
            }
            // s-t間最短路に沿って目一杯流す
            ll d = f;
            for(ll v = t; v != s; v = prevv[v]){
                d = min(d, graph[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d*h[t];
            for(ll v = t; v != s; v = prevv[v]){
                Edge &e = graph[prevv[v]][preve[v]];
                e.cap -= d;
                graph[v][e.rev].cap += d;
            }
        }
        return res;
    }
};


int main(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<vector<ll>> acc(n+1, vector<ll>(n+1));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
            acc[i+1][j+1] = acc[i+1][j]+acc[i][j+1]-acc[i][j]+a[i][j];
        }
    }
    auto id = [&](int i, int j) -> int{
        return i*(n-m+1)+j;
    };
    vector<ll> d((n-m+1)*(n-m+1));
    rep(i, 0, n-m+1){
        rep(j, 0, n-m+1){
            d[id(i, j)] = acc[i+m][j+m]-acc[i+m][j]-acc[i][j+m]+acc[i][j];
        }
    }
    MinCostFlow mcf((n-m+1)*(n-m+1)+2);
    int total = (n-m+1)*(n-m+1);
    int s = total, t = total+1;
    rep(i, 0, (n-m+1)*(n-m+1)){
        mcf.add_edge(s, i, 1, -d[i]);
        mcf.add_edge(i, t, 1, 0);
    }

    cout << -mcf.min_cost_flow(s, t, 3) << endl;
    
    return 0;
}