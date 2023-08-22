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
// https://atcoder.jp/contests/abc061/tasks/abc061_d

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
}


int main(){
    ll n, m; cin >> n >> m;
    vector<Edge> edges(m);
    rep(i, 0, m){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges[i].from = a;
        edges[i].to = b;
        edges[i].cost = -c;
    }

    vector<ll> dist(n);
    BellmanFord(edges, dist, 0);
    ll ans = -dist[n-1];
    vector<bool> isNegative(n, false);

    rep(i, 0, (int)dist.size()){
		for (const auto& edge : edges){
            if(dist[edge.from] == INF) continue;
			const ll d = (dist[edge.from] + edge.cost);
			if (d < dist[edge.to]){
				dist[edge.to] = d;
                isNegative[edge.to] = true;
			}

            if(isNegative[edge.from]) isNegative[edge.to] = true;
		}
    }

    if(isNegative[n-1]) cout << "inf" << endl;
    else cout << ans << endl;
    
    return 0;
}