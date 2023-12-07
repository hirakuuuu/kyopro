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
// 

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
    ll n, m, p; cin >> n >> m >> p;
    vector<Edge> edges(m);
    rep(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges[i].from = a;
        edges[i].to = b;
        edges[i].cost = -(c-p);
    }
    vector<ll> dist(n, INF);
    BellmanFord(edges, dist, 0);

    if(dist[n-1] == -INF){
        cout << -1 << endl;
    }else{
        cout << max(0LL, -dist[n-1]) << endl;
    }



    return 0;
}