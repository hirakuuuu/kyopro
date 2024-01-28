#include <bits/stdc++.h>
using namespace std;
#define ll long long

// ここから
class RollbackUnionFind {
    vector<ll> parent;
    stack<pair<int, int>> history;
    set<int> roots;
    int inner_snap;

    inline ll find(ll n){
        // 経路圧縮を行わない
        return (parent[n] < 0? n:find(parent[n]));
    }
public:
    RollbackUnionFind(ll n_ = 1): parent(n_, -1), inner_snap(0){
        for(int i = 0; i < n_; i++) roots.insert(i);
    }

    inline bool same(ll x, ll y){
        return find(x) == find(y);
    }

    inline void unite(ll x, ll y){
        ll rx = find(x);
        ll ry = find(y);
        if(parent[rx] > parent[ry]) swap(rx, ry);
        history.emplace(rx, parent[rx]);
        history.emplace(ry, parent[ry]);
        if(rx == ry) return;
        parent[rx] += parent[ry];
        parent[ry] = rx;
        roots.erase(ry); // ryは根じゃなくなるので、削除
    }

    // rollback処理（stackの上2つを使って戻す）
    inline void undo(){
        auto [y, py] = history.top();
        parent[y] = py;
        history.pop();
        auto [x, px] = history.top();
        parent[x] = px;
        history.pop();
        if(parent[y] < 0) roots.insert(y); // 根に戻す（根になっていなくてもｘが追加されるだけなのでOK）
    }

    void snapshot() { inner_snap = int(history.size() >> 1); }

    int get_state() { return int(history.size() >> 1); }

    void rollback(int state = -1) {
        if (state == -1) state = inner_snap;
        state <<= 1;
        assert(state <= (int)history.size());
        while (state < (int)history.size()) undo();
    }

    inline ll size(ll x){
        return (-parent[find(x)]);
    }

    inline ll operator[](ll x){
        return find(x);
    }

    inline ll partial(){
        return (ll)roots.size();
    }

    void clear(){
        for(int i = 0; i < (ll)parent.size(); i++){
            parent[i] = -1;
        }
    }
};

class OfflineDynamicConnectivity {
    ll N, Q, segsz;
    RollbackUnionFind uf;
    vector<vector<pair<int, int>>> seg, qadd, qdel;
    unordered_map<ll, pair<int, int>> cnt;

    // 時刻[l, r) で辺 e が存在することを記録
    void segment(pair<int, int>& e, int l, int r) {
        int L = l + segsz;
        int R = r + segsz;
        while (L < R) {
            if (L & 1) seg[L++].push_back(e);
            if (R & 1) seg[--R].push_back(e);
            L >>= 1, R >>= 1;
        }
    }

public:
    OfflineDynamicConnectivity(int n, int q): N(n), Q(q), uf(n), qadd(q), qdel(q) {
        segsz = 1;
        while(segsz < Q) segsz *= 2;
        seg.resize(segsz*2);
    }

    // 時刻ｔに u, v をつなぐ辺を追加
    void add_edge(int t, int u, int v){
        if(u > v) swap(u, v);
        qadd[t].emplace_back(u, v);
    }
    // 時刻ｔに u, v をつなぐ辺を削除
    void del_edge(int t, int u, int v){
        if(u > v) swap(u, v);
        qdel[t].emplace_back(u, v);
    }

    void build() {
        for(int i = 0; i < Q; i++){
            for(auto& e: qadd[i]){
                ll edge_num = (e.first*(1LL<<20)+e.second);
                auto& dat = cnt[edge_num];
                if(dat.second++ == 0) dat.first = i;
            }
            for(auto& e: qdel[i]){
                ll edge_num = (e.first*(1LL<<20)+e.second);
                auto& dat = cnt[edge_num];
                if(--dat.second == 0) segment(e, dat.first, i);
            }
        }
        for(auto& [key, dat]: cnt){
            if(dat.second != 0){
                pair<int, int> e = {key/(1LL<<20), key%(1LL<<20)};
                segment(e, dat.first, Q);
            }
        }
    }

    // [l, r) の区間での処理
    template <typename ADD, typename DEL, typename QUERY>
    void dfs(const ADD& add, const DEL& del, const QUERY& query, int id, int l, int r){
        if(Q <= l) return;
        int state = uf.get_state(); // 現在のufの状態（stackのサイズ）
        vector<pair<int, int>> es;
        for(auto& [u, v]: seg[id]){
            uf.unite(u, v);
            es.emplace_back(u, v);
        }
        if(l+1 == r){
            query(l, uf.partial());
        } else {
            dfs(add, del, query, id*2, l, (l+r)>>1);
            dfs(add, del, query, id*2+1, (l+r)>>1, r);
        }
        uf.rollback(state);
    }

    template <typename ADD, typename DEL, typename QUERY>
    void run(const ADD& add, const DEL& del, const QUERY& query) {
        dfs(add, del, query, 1, 0, segsz);
    }
};
// ここまで

// verify
// https://codeforces.com/gym/100551/problem/A

int main(){
    string infilename = "connect.in";
    string outfilename = "connect.out";
    ifstream cin(infilename);
    ofstream cout(outfilename);
    int n, q; cin >> n >> q;
    vector<char> t(q);
    vector<int> u(q), v(q);
    OfflineDynamicConnectivity dc(n, q);
    vector<int> question;

    for(int i = 0; i < q; i++){
        cin >> t[i];
        if(t[i] == '+'){
            cin >> u[i] >> v[i];
            u[i]--, v[i]--;
            if(u[i] > v[i]) swap(u[i], v[i]);
            dc.add_edge(i, u[i], v[i]);
        }else if(t[i] == '-'){
            cin >> u[i] >> v[i];
            u[i]--, v[i]--;
            if(u[i] > v[i]) swap(u[i], v[i]);
            dc.del_edge(i, u[i], v[i]);
        }else{
            question.push_back(i);
        }
    }

    set<int> roots;
    for(int i = 0; i < n; i++) roots.insert(i);
    vector<ll> ans(q+1);
    auto add = [&](int a, int b) -> void {};
    auto del = [&](int a, int b) -> void {};
    auto query = [&](int l, ll part) -> void {
        ans[l] = part;
    };

    dc.build();
    dc.run(add, del, query);

    for(auto qq: question){
        cout << ans[qq] << endl;
    }
    return 0;
}