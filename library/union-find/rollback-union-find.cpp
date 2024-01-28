#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 参考
// https://nyaannyaan.github.io/library/data-structure/rollback-union-find.hpp

// ここから
class RollbackUnionFind {
    vector<ll> parent, maxi, mini;
    stack<pair<int, int>> history;
    int inner_snap;

    inline ll find(ll n){
        // 経路圧縮を行わない
        return (parent[n] < 0? n:find(parent[n]));
    }
public:
    RollbackUnionFind(ll n_ = 1): parent(n_, -1), maxi(n_), mini(n_), inner_snap(0){
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }

    inline bool same(ll x, ll y){
        return find(x) == find(y);
    }

    inline void unite(ll x, ll y){
        ll rx = find(x);
        ll ry = find(y);
        history.emplace(x, parent[x]);
        history.emplace(y, parent[y]);
        if(rx == ry) return;
        if(parent[rx] > parent[ry]) swap(rx, ry);
        parent[rx] += parent[ry];
        parent[ry] = rx;
        maxi[x] = std::max(maxi[x],maxi[y]);
        mini[x] = std::min(mini[x],mini[y]);
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

    inline ll min(ll x){
        return mini[find(x)];
    }

    inline ll max(int x){
        return mini[find(x)];
    }

    inline ll size(ll x){
        return (-parent[find(x)]);
    }

    inline ll operator[](ll x){
        return find(x);
    }

    void clear(){
        for(int i = 0; i < (ll)parent.size(); i++){
            parent[i] = -1;
        }
        iota(maxi.begin(), maxi.end(), 0);
        iota(mini.begin(), mini.end(), 0);
    }
};
// ここまで

// verify
// https://judge.yosupo.jp/problem/persistent_unionfind

int main(){
    int n, q; cin >> n >> q;
    vector<int> t(q+1), k(q+1), u(q+1), v(q+1);
    vector<vector<int>> g(q+1);
    vector<vector<tuple<int, int, int>>> queri(q+1);
    for(int i = 1; i <= q; i++){
        cin >> t[i] >> k[i] >> u[i] >> v[i];
        k[i]++;
        if(t[i] == 0){
            g[k[i]].push_back(i);
        }else{
            queri[k[i]].push_back({i, u[i], v[i]});
        }
    }
    
    RollbackUnionFind ruf(n);
    vector<pair<int, int>> ans;
    auto dfs = [&](auto sfs, int pos) -> void {
        for(auto [i, nu, nv]: queri[pos]){
            if(ruf.same(nu, nv)) ans.push_back({i, 1});
            else ans.push_back({i, 0});
        }
        for(auto nxt: g[pos]){
            ruf.unite(u[nxt], v[nxt]);
            sfs(sfs, nxt);
            ruf.undo();
        }
    };
    dfs(dfs, 0);
    sort(ans.begin(), ans.end());
    for(auto aa: ans){
        cout << aa.second << endl;
    }
}