#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
カメラを置く向きは，下向きと右向きに絞ってよい．
また，下向きカメラを置くマスは，その一つ上のマスに障害物があるとしてよい．(右向きも同様)
障害物がない直線上のマスの集合で極大なものを考えると，カメラを置く位置は一意に定まる．
縦，横でそのマスの集合の集合を考え，同じマスが属するマスをつないだ二部グラフを考えると，元の問題は最小頂点被覆に一致する．
二部グラフの最大頂点被覆は，最大マッチングに帰着され，これは最大流を求めればよい．
*/

template <class Cap> 
class Dinic {
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;

public:
    Dinic(): _n(0) {}
    explicit Dinic(int n): _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap){
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = (int)pos.size();
        pos.push_back({from, (int)g[from].size()});
        int from_id = (int)g[from].size();
        int to_id = (int)g[to].size();
        if(from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge{
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i){
        int m = (int)pos.size();
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap+_re.cap, _re.cap};
    }

    vector<edge> edges(){
        int m = (int)pos.size();
        vector<edge> result;
        for(int i = 0; i < m; i++){
            result.push_back(get_edge(i));
        }
        return result;
    }

    void change_edge(int i, Cap new_cap, Cap new_flow){
        int m = (int)pos.size();
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap-new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t){
        return flow(s, t, numeric_limits<Cap>::max());
    }
    // s!=t である必要あり
    Cap flow(int s, int t, Cap flow_limit){
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        vector<int> level(_n), iter(_n);
        queue<int> que;

        auto bfs = [&]()->void {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            queue<int>().swap(que);
            que.push(s);
            while(!que.empty()){
                int v = que.front(); que.pop();
                for(auto e: g[v]){
                    if(e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v]+1;
                    if(e.to == t) return;
                    que.push(e.to);
                }
            }
        };

        auto dfs = [&](auto self, int v, Cap up)->Cap {
            if(v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for(int& i = iter[v]; i < (int)g[v].size(); i++){
                _edge& e = g[v][i];
                if(level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d = self(self, e.to, min(up-res, g[e.to][e.rev].cap));
                if(d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if(res == up) return res;
            }
            level[v] = _n;
            return res;
        };
        
        Cap flow = 0;
        while(flow < flow_limit){
            bfs();
            if(level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit-flow);
            if(!f) break;
            flow += f;
        }
        return flow;
    }

    // 最小カットをした上で、頂点 s 側に属する頂点集合を返す
    vector<bool> min_cut(int s){
        vector<bool> visited(_n);
        queue<int> que;
        while(!que.empty()){
            int p = que.front(); que.pop();
            visited[p] = true;
            for(auto e: g[p]){
                if(e.cap && !visited[e.to]){
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
};

int main(){
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    vector<vector<int>> S(h, vector<int>(w, -1));
    vector<vector<int>> T(h, vector<int>(w, -1));
    int id = 0;
    {
        rep(i, 0, h) rep(j, 0, w){
            if(s[i][j] == '#') continue;
            if(j == 0 || s[i][j-1] == '#') id++;
            S[i][j] = id;
        }
        rep(i, 0, w) rep(j, 0, h){
            if(s[j][i] == '#') continue;
            if(j == 0 || s[j-1][i] == '#') id++;
            T[j][i] = id;
        }
    }

    Dinic<int> mf(id+2);
    int source = id, target = id+1;
    map<pair<int, int>, bool> seen;
    rep(i, 0, h) rep(j, 0, w){
        if(s[i][j] == '#') continue;
        if(!seen[{source, S[i][j]-1}]){
            seen[{source, S[i][j]-1}] = true;
            mf.add_edge(source, S[i][j]-1, 1);
        }
        if(!seen[{T[i][j]-1, target}]){
            seen[{T[i][j]-1, target}] = true;
            mf.add_edge(T[i][j]-1, target, 1);
        }
        if(!seen[{S[i][j]-1, T[i][j]-1}]){
            seen[{S[i][j]-1, T[i][j]-1}] = true;
            mf.add_edge(S[i][j]-1, T[i][j]-1, 1);
        }
    }
    cout << mf.flow(source, target) << endl;
    

    return 0;
}