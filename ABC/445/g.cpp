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

// 最大フロー問題を解くためのアルゴリズム
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
        que.push(s);
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
    int n, a, b; cin >> n >> a >> b;
    vector<int> dx = {-a, -a, a, a, -b, -b, b, b};
    vector<int> dy = {-b, b, -b, b, -a, a, -a, a};
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    vector<vector<int>> col(n, vector<int>(n, -1));
    rep(i, 0, n){
        rep(j, 0, n){
            if(s[i][j] == '#') continue;
            if(col[i][j] != -1) continue;
            queue<pair<int, int>> que;
            que.push({i, j});
            col[i][j] = 0;
            while(!que.empty()){
                auto [pi, pj] = que.front(); que.pop();
                rep(k, 0, 8){
                    int ni = pi+dx[k], nj = pj+dy[k];
                    if(!inr(0, ni, n) || !inr(0, nj, n) || s[ni][nj] == '#') continue;
                    if(col[ni][nj] != -1) continue;
                    col[ni][nj] = 1-col[pi][pj];
                    que.push({ni, nj});
                }
            }
        }
    }

    Dinic<ll> g(1+n*n+1);
    int source = n*n, target = n*n+1;
    rep(i, 0, n){
        rep(j, 0, n){
            if(col[i][j] == -1) continue;
            if(col[i][j] == 0){
                g.add_edge(source, i*n+j, 1);
                rep(k, 0, 8){
                    int ni = i+dx[k], nj = j+dy[k];
                    if(!inr(0, ni, n) || !inr(0, nj, n) || s[ni][nj] == '#') continue;
                    g.add_edge(i*n+j, ni*n+nj, 1);
                }
            }else{
                g.add_edge(i*n+j, target, 1);
            }
        }
    }
    g.flow(source, target);
    
    // 二部グラフの最大独立集合
    // Sから残余グラフ上で到達可能な頂点の集合を得る
    vector<bool> cut = g.min_cut(source);
    rep(i, 0, n){
        rep(j, 0, n){
            if(s[i][j] == '#') continue;
            
            // source とつながってる側で到達できる頂点
            if(cut[i*n+j] && col[i][j] == 0){
                s[i][j] = 'o';
            // target とつながってる側が到達できない頂点
            }else if(!cut[i*n+j] && col[i][j] == 1){
                s[i][j] = 'o';
            }
        }
    }

    rep(i, 0, n){
        cout << s[i] << endl;
    }
    return 0;
}