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

// 辺
struct Edge
{
	int from;
	int to;
	ll cost;
    Edge(int from_, int to_, ll cost_): from(from_), to(to_), cost(cost_) {}
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
    int n; cin >> n;
    map<string, int> id;
    vector<string> S;
    {
        int id_ = 0;
        id[""] = id_++;
        S.push_back("");
        rep(i, 0, 26){
            string s; s += (char)('a'+i);
            id[s] = id_++;
            S.push_back(s);
        }
        rep(i, 0, 26) rep(j, 0, 26){
            string s;
            s += (char)('a'+i);
            s += (char)('a'+j);
            id[s] = id_++;
            S.push_back(s);
        }
        rep(i, 0, 26) rep(j, 0, 26) rep(k, 0, 26){
            string s;
            s += (char)('a'+i);
            s += (char)('a'+j);
            s += (char)('a'+k);
            id[s] = id_++;
            S.push_back(s);
        }
    }

    vector<ll> s(18278+1);
    vector<string> t(n);
    rep(i, 0, n){
        cin >> t[i];
        ll p; cin >> p;
        s[id[t[i]]] = p;
    }
    {
        vector<ll> pre = s;
        for(auto ss: S){
            int m = (int)ss.size();
            rep(j, 1, m) s[id[ss]] += pre[id[ss.substr(j, m-j)]];
        }
    }


    vector<Edge> edges;
    {
        rep(i, 0, 26){
            string a; a += (char)('a'+i);
            edges.push_back(Edge(id[""], id[a], -s[id[a]]));
        }
        rep(i, 0, 26) rep(j, 0, 26){
            string a;
            a += (char)('a'+i);
            a += (char)('a'+j);
            edges.push_back(Edge(id[a.substr(0, 1)], id[a], -s[id[a]]));

            rep(k, 0, 26){
                string b = a.substr(1, 1)+(char)('a'+k);
                string c = a+(char)('a'+k);
                edges.push_back(Edge(id[a], id[b], -s[id[c]])); 
            }
        }
    }

    vector<ll> dist(26+26*26+1);
    ll ans = -INF;
    BellmanFord(edges, dist, 0);
    rep(i, 1, 26+26*26+1){
        if(dist[i] == -INF){
            cout << "Infinity" << endl;
            return 0;
        }
        chmax(ans, -dist[i]);
    }
    cout << ans << endl;
    
    return 0;
}