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

// 0ならば素数, 0でないなら最小の素因数
const int MAX_N = 3000005;
vector<int> min_prime(MAX_N+1);
void eratosthenes(){
    rep(i, 2LL, (ll)sqrt(MAX_N)+1){
        if(min_prime[i] == 0){
            for(ll j = i*i; j <= MAX_N; j += i){
                if(min_prime[j] == 0) min_prime[j] = i;
            }
        }
    }
}

// 素因数分解 O(log{x})
vector<pair<int, int>> prime_factorization(ll x){
    vector<pair<int, int>> res;
    while(min_prime[x] != 0){
        ll p = min_prime[x];
        res.push_back({p, 0});
        while(x%p == 0){
            x /= p;
            res.back().second++;
        }
    }
    if(x != 1) res.push_back({x, 1});
    return res;
};

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
    eratosthenes();
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> primes_a(n);
    vector<vector<int>> primes_b(n);
    map<int, int> pid;
    int id = 0;
    rep(i, 0, n){
        cin >> a[i] >> b[i];
        if(a[i] == 1 || b[i] == 1){
            continue;
        }
        vector<pair<int, int>> pf_a = prime_factorization(a[i]);
        for(auto [p, _]: pf_a){
            if(p == 1) continue;
            primes_a[i].push_back(p);
            if(!pid.count(p)){
                pid[p] = id++;
            }
        }
        vector<pair<int, int>> pf_b = prime_factorization(b[i]);
        for(auto [p, _]: pf_b){
            if(p == 1) continue;
            primes_b[i].push_back(p);
            if(!pid.count(p)){
                pid[p] = id++;
            }
        }
    }
    int m = id;
    Dinic<ll> g(3*n+m+2);
    int source = 3*n+m, target = 3*n+m+1;
    int cnt = 0;
    rep(i, 0, n){
        g.add_edge(source, i, INF);
        if(a[i] == 1 || b[i] == 1){
            g.add_edge(i, target, 1);
        }else{
            g.add_edge(i, n+i, primes_a[i].size());
            for(auto p: primes_a[i]){
                g.add_edge(n+i, 3*n+pid[p], 1);
            }
            g.add_edge(i, 2*n+i, primes_b[i].size());
            for(auto p: primes_b[i]){
                g.add_edge(2*n+i, 3*n+pid[p], 1);
            }
        }
    }
    for(auto [p, val]: pid){
        g.add_edge(3*n+val, target, 1);
    }

    
    return 0;
}