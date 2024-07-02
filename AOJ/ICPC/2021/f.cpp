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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// ここから
class RollbackUnionFind {
    vector<ll> parent;
    stack<pair<int, int>> history;
    int inner_snap;


public:
    RollbackUnionFind(ll n_ = 1): inner_snap(0){ parent.assign(n_, -1); }

    inline int find(int x){
        // 経路圧縮を行わない
        return (parent[x] < 0? x:find(parent[x]));
    }

    inline bool same(int x, int y){
        return find(x) == find(y);
    }

    inline bool unite(int x, int y){
        x = find(x), y = find(y);
        history.emplace(x, parent[x]);
        history.emplace(y, parent[y]);
        if(x == y) return false;
        if(parent[x] > parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }

    // rollback処理（stackの上2つを使って戻す）
    inline void undo(){
        parent[history.top().first] = history.top().second;
        history.pop();
        parent[history.top().first] = history.top().second;
        history.pop();
    }

    void snapshot() { inner_snap = int(history.size() >> 1); }

    int get_state() { return int(history.size() >> 1); }

    void rollback(int state = -1) {
        if (state == -1) state = inner_snap;
        state <<= 1;
        assert(state <= (int)history.size());
        while (state < (int)history.size()) undo();
    }

    inline int size(int x){
        return (-parent[find(x)]);
    }

    inline int operator[](int x){
        return find(x);
    }
};

int main(){
    while(true){
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0) break;

        vector<vector<pair<int, int>>> edge(100005);
        vector<vector<bool>> connect(100005);
        vector<vector<pair<int, int>>> g(n);
        rep(i, 0, m){
            int a, b, s; cin >> a >> b >> s;
            a--, b--;
            edge[s].push_back({a, b});
            g[a].push_back({b, s});
            g[b].push_back({a, s});
        }
        RollbackUnionFind uf(n);
        rrep(i, 100000, 1){
            for(auto [u, v]: edge[i]){
                connect[i].push_back(!uf.same(u, v));
                uf.unite(u, v);
            }
            reverse(edge[i].begin(), edge[i].end());
            reverse(connect[i].begin(), connect[i].end());
        }
        set<pair<int, int>> c;
        c.insert({uf.size(0), uf[0]});
        vector<bool> ng(n, false);
        rep(i, 1, 100001){
            rep(j, 0, edge[i].size()){
                auto [u, v] = edge[i][j];
                // cout << u << ' ' << v << ' ' << (connect[i][j] ? "connect": "no") << endl;
                int sz = uf.size(u), root = uf[u];
                uf.undo();
                if(!connect[i][j]) continue;
                int pu = uf[u], pv = uf[v];
                if(!ng[u] && !ng[v] && pu != pv){
                    c.erase(c.find({sz, root}));
                    c.insert({uf.size(u), pu});
                    c.insert({uf.size(v), pv});
                }
            }

            int mx = (*c.rbegin()).first;
            if(mx == 1) break;
            while((*c.begin()).first < mx){
                auto [s, r] = (*c.begin());
                c.erase(c.begin());
                queue<int> que;
                que.push(r);
                ng[r] = 1;
                while(!que.empty()){
                    int q = que.front(); que.pop();
                    for(auto [nq, cost]: g[q]){
                        if(cost <= i) continue;
                        if(ng[nq]) continue;
                        ng[nq] = 1;
                        que.push(nq);
                    }
                }
            }
        }

        vector<int> ans;
        rep(i, 0, n){
            if(ng[i]) continue;
            ans.push_back(i+1);
        }
        cout << ans[0];
        rep(i, 1, ans.size()){
            cout << ' ' << ans[i];
        }
        cout << endl;

    }

    return 0;
}