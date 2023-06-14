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

// https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/bellman-ford


// 辺
struct Edge
{
	int from;
	int to;
	int cost;
};

// ベルマンフォード法 (基本実装)
// 負閉路が存在する場合 true を返す
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
bool BellmanFord(vector<Edge> &edges, vector<ll> &dist, int start){
    fill(dist.begin(), dist.end(), INF);
	dist[start] = 0;
    // 負の閉路がなければ、(頂点数-1)回の更新で最短路が決まる
	rep(i, 0, (int)dist.size()-1){
		bool changed = false;
		// 各辺について
		for (const auto& edge : edges){
			// to までの新しい距離
			const ll d = (dist[edge.from] + edge.cost);
			// d が現在の記録より小さければ更新
			if (d < dist[edge.to]){
				dist[edge.to] = d;
				changed = true;
			}
		}
		// どの頂点も更新されなかったら終了
		if (!changed){
			return false;
		}
	}
	// 頂点回数分だけループしても更新が続くのは, 負閉路が存在するから
	return true;
}

int main(){
    
    return 0;
}