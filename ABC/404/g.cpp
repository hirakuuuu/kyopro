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

// 整理すると，線形不等式制約つきの最小化問題になるので，牛ゲーになる
// 
// 牛ゲー: d_j-d_i <= c(i, j) という制約があるうえで d_0-d_n を最大化する問題
//         → i -> j にコスト c(i, j) の辺があると思って 0 から n への最短距離を求めればよい

// 辺
struct Edge
{
	ll from;
	ll to;
	ll cost;
};

// ベルマンフォード法 (基本実装)
// 負閉路が存在する場合 true を返す
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void BellmanFord(vector<Edge> &edges, vector<ll> &dist, int start){
    fill(dist.begin(), dist.end(), INF);
	dist[start] = 0;
    // 負の閉路がなければ、(頂点数-1)回の更新で最短路が決まる
	rep(i, 0, (int)dist.size()-1){
		// 各辺について
		for (const auto& edge : edges){
			// to までの新しい距離
			const ll d = (dist[edge.from] + edge.cost);
			// d が現在の記録より小さければ更新
			if (dist[edge.from] != INF && d < dist[edge.to]){
				dist[edge.to] = d;
			}
		}
	}

	// 負閉路が影響を与える範囲を計算
	rep(i, 0, (int)dist.size()){
		// 各辺について
		for (const auto& edge : edges){
			// to までの新しい距離
			const ll d = (dist[edge.from] + edge.cost);
			// d が現在の記録より小さければ更新
			if (d < dist[edge.to] && dist[edge.from] != INF){
				dist[edge.to] = -INF;
			}
		}
	}
}


int main(){
    int n, m; cin >> n >> m;
    vector<ll> l(m), r(m), s(m);
    vector<Edge> edges;
    vector<vector<pair<ll, ll>>> gl(n+1);
    rep(i, 0, m){
        cin >> l[i] >> r[i] >> s[i];
        // s[i] -= r[i]-l[i]+1;
        Edge e1, e2;
        e1.from = l[i]-1, e1.to = r[i], e1.cost = -s[i];
        e2.from = r[i], e2.to = l[i]-1, e2.cost = s[i];
        edges.push_back(e1);
        edges.push_back(e2);
    }
    rep(i, 0, n){
        Edge e;
        e.from = i, e.to = i+1, e.cost = -1;
        edges.push_back(e);
    }

    vector<ll> dist(n+1);
    BellmanFord(edges, dist, 0);
    // rep(i, 0, n+1){
    //     cout << dist[i] << endl;
    // }
    if(dist[n] == -INF) cout << -1 << endl;
    else cout << -dist[n] << endl;
    
    
    return 0;
}