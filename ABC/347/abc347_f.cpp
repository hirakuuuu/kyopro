#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
<<<<<<< HEAD
#define ll long long
=======
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
>>>>>>> e88c86edd4c87da6ad92df9772fe439b2de70ce7
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

<<<<<<< HEAD
template <typename F>
struct SegmentTree2D {
 private:
  int id(int h, int w) const { return h * 2 * W + w; }

 public:
  int H, W;
  vector<ll> seg;
  const F f;
  const ll I;

  SegmentTree2D(int h, int w, F _f, const ll& i) : f(_f), I(i) { init(h, w); }

  void init(int h, int w) {
    H = W = 1;
    while (H < h) H <<= 1;
    while (W < w) W <<= 1;
    seg.assign(4 * H * W, I);
  }

  // build にのみ呼ぶ
  void set(int h, int w, const ll& x) { seg[id(h + H, w + W)] = x; }

  void build() {
    // w in [W, 2W)
    for (int w = W; w < 2 * W; w++) {
      for (int h = H - 1; h; h--) {
        seg[id(h, w)] = f(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
      }
    }
    // h in [0, 2H)
    for (int h = 0; h < 2 * H; h++) {
      for (int w = W - 1; w; w--) {
        seg[id(h, w)] = f(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
      }
    }
  }

  ll get(int h, int w) const { return seg[id(h + H, w + W)]; }
  ll operator()(int h, int w) const { return seg[id(h + H, w + W)]; }

  void update(int h, int w, const ll& x) {
    h += H, w += W;
    seg[id(h, w)] = x;
    for (int i = h >> 1; i; i >>= 1) {
      seg[id(i, w)] = f(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
    }
    for (; h; h >>= 1) {
      for (int j = w >> 1; j; j >>= 1) {
        seg[id(h, j)] = f(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
      }
    }
  }

  ll _inner_query(int h, int w1, int w2) {
    ll res = I;
    for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
      if (w1 & 1) res = f(res, seg[id(h, w1)]), w1++;
      if (w2 & 1) --w2, res = f(res, seg[id(h, w2)]);
    }
    return res;
  }

  // [ (h1,w1), (h2,w2) ) 半開
  ll query(int h1, int w1, int h2, int w2) {
    if (h1 >= h2 || w1 >= w2) return I;
    ll res = I;
    h1 += H, h2 += H, w1 += W, w2 += W;
    for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
      if (h1 & 1) res = f(res, _inner_query(h1, w1, w2)), h1++;
      if (h2 & 1) --h2, res = f(res, _inner_query(h2, w1, w2));
    }
    return res;
  }
};

int main(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n+1, vector<ll>(n+1));
    vector<vector<ll>> acc(n+1, vector<ll>(n+1));
    SegmentTree2D seg(n-m+1, n-m+1, [](ll a, ll b) { return max(a, b); }, 0LL);
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            cin >> a[i][j];
        }
    }
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            acc[i][j] = a[i][j]+acc[i-1][j]+acc[i][j-1]-acc[i-1][j-1];
        }
    }
    rep(i, 0, n-m+1){
        rep(j, 0, n-m+1){
            ll tmp = acc[i+m][j+m]-acc[i][j+m]-acc[i+m][j]+acc[i][j];
            seg.set(i, j, tmp);
        }
    }

    seg.build();
    ll ans = 0;
    // 縦３つに分ける
    rep(i, 0, n-2*m+1){
        ll area1 = seg.query(0, 0, i+1, n-m+1);
        rep(j, i+m, n-m+1){
            if(i+m >= n-m+1 || j+m >= n-m+1) break;
            ll area2 = seg.query(i+m, 0, j+1, n-m+1);
            ll area3 = seg.query(j+m, 0, n-m+1, n-m+1);
            // cout << i << ' ' << j << ' ' << area1 << ' ' << area2 << ' ' << area3 << endl;
            chmax(ans, area1+area2+area3);
        }
    }

    // 横３つに分ける
    rep(i, 0, n-2*m+1){
        rep(j, i+m, n-m+1){
          ll area1 = seg.query(0, 0, n-m+1, i+1);
            if(i+m >= n-m+1 || j+m >= n-m+1) break;
            ll area2 = seg.query(0, i+m, n-m+1, j+1);
            ll area3 = seg.query(0, j+m, n-m+1, n-m+1);
            // cout << i << ' ' << j << ' ' << area1 << ' ' << area2 << ' ' << area3 << endl;
            chmax(ans, area1+area2+area3);
        }
    }

    // 縦棒、横棒|-
    rep(i, 0, n-m+1){
        ll area1 = seg.query(0, 0, n-m+1, i+1);
        rep(j, 0, n-2*m+1){
            if(i+m >= n-m+1 || j+m >= n-m+1) break;
            ll area2 = seg.query(0, i+m, j+1, n-m+1);
            ll area3 = seg.query(j+m, i+m, n-m+1, n-m+1);
            // cout << i << ' ' << j << ' ' << area1 << ' ' << area2 << ' ' << area3 << endl;
            chmax(ans, area1+area2+area3);
        }
    }
    // 上
    rep(i, 0, n-2*m+1){
        rep(j, 0, n-2*m+1){
            if(i+m >= n-m+1 || j+m >= n-m+1) break;
            ll area1 = seg.query(0, 0, j+1, i+1);
            ll area2 = seg.query(0, i+m, j+1, n-m+1);
            ll area3 = seg.query(j+m, 0, n-m+1, n-m+1);
            // cout << i << ' ' << j << ' ' << area1 << ' ' << area2 << ' ' << area3 << endl;
            chmax(ans, area1+area2+area3);
        }
    }
    // 横棒、縦棒-|
    rep(i, 0, n-2*m+1){
        rep(j, 0, n-m+1){
            if(i+m >= n-m+1 || j+m >= n-m+1) break;
            ll area1 = seg.query(0, 0, i+1, j+1);
            ll area2 = seg.query(i+m, 0, n-m+1, j+1);
            ll area3 = seg.query(0, j+m, n-m+1, n-m+1);
            // cout << i << ' ' << j << ' ' << area1 << ' ' << area2 << ' ' << area3 << endl;
            chmax(ans, area1+area2+area3);
        }
    }
    // 下
    rep(i, 0, n-2*m+1){
        ll area1 = seg.query(0, 0, i+1, n-m+1);
        rep(j, 0, n-2*m+1){
            if(i+m >= n-m+1 || j+m >= n-m+1) break;
            ll area2 = seg.query(i+m, 0, n-m+1, j+1);
            ll area3 = seg.query(i+m, j+m, n-m+1, n-m+1);
            // cout << i << ' ' << j << ' ' << area1 << ' ' << area2 << ' ' << area3 << endl;
            chmax(ans, area1+area2+area3);
        }
    }
    cout << ans << endl;



=======
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
    
>>>>>>> e88c86edd4c87da6ad92df9772fe439b2de70ce7
    return 0;
}