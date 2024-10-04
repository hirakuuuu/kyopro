#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long

/*
HL分解
- 木は更新に弱いが、配列は更新に強い → 木を少ない数の配列で表現すれば、小さい計算量で更新ができる
- 辺を HeavyPath (部分木のサイズが最大の子に向かうパス), LightPath (それ以外) に分解し、
  HeavyPath でつながった頂点をまとめて, LightPath を辺とする木を考えると, 高さが O(\log{n}) となる



 * コード中でreal, hld のid/nodeという表記があるが、
 * real: 入力時点での木のノード番号
 * hld: HLDの配列上のindex
 * を示す. 

ToDo: https://judge.yosupo.jp/submission/72507
*/

// Reference: https://qiita.com/recuraki/items/cb888afdc107b64a4a6e
class HeavyLightDecomposition{
    int n; // 頂点数
    vector<vector<int>> g;
    vector<int> depthRealnode;    // 実ノードの深さ
    vector<int> parentRealnode;   // 実IDでの親（実ID）
    vector<int> childNumRealnode; // 部分木の頂点数, 自分自身も含める
    vector<int> shallowRealnode;  // 実ノードに対して, その所属する列の深さが最も浅いノード（実ID）
    vector<int> realid2hldid;     // 実IDからHLD上のIDへのマッピング
    vector<int> hldid2realid;     // HLD上のIDから実IDへのマッピング

    // HLD の前処理. 確実ノードの深さと親を調べる. 計算量: O(n)
    void _dfs(int root, int d){
        depthRealnode[root] = d;
        for(int i = 0; i < (int)g[root].size(); i++){
            int nxt = g[root][i];
            if(parentRealnode[nxt] != -1) continue;
            if(nxt == parentRealnode[root]) continue;
            parentRealnode[nxt] = root;
            _dfs(nxt, d+1);
            childNumRealnode[root] += childNumRealnode[nxt];  
        }
    }

    // HL分解
    void _hld(int curRealnode, int topNode){
        realid2hldid[curRealnode] = (int)hldid2realid.size();
        hldid2realid.push_back(curRealnode);
        shallowRealnode[curRealnode] = topNode;

        if(childNumRealnode[curRealnode] == 1) return; // 葉なら終わり

        // 子の探索
        int maxVal = 0, maxInd = -1;
        for(int i = 0; i < (int)g[curRealnode].size(); i++){
            int nxt = g[curRealnode][i];
            if(nxt == parentRealnode[curRealnode]) continue;
            if(childNumRealnode[nxt] > maxVal){
                maxVal = childNumRealnode[nxt];
                maxInd = nxt;
            }
        }
        
        // HeavyPath の探索
        _hld(maxInd, topNode);

        // LightPath の探索
        for(int i = 0; i < (int)g[curRealnode].size(); i++){
            int nxt = g[curRealnode][i];
            if(nxt == parentRealnode[curRealnode]) continue;
            if(nxt == maxInd) continue;
            _hld(nxt, nxt); // shallowNode (列の先頭) はその頂点自身になる
        }
    }

public:
    HeavyLightDecomposition(int n_): n(n_){
        g.assign(n, vector<int>());
        depthRealnode.assign(n, -1);
        parentRealnode.assign(n, -1);
        childNumRealnode.assign(n, 1);
        shallowRealnode.assign(n, 0);
        realid2hldid.assign(n, -1);
        hldid2realid.clear();
    }

    // 辺 (u, v) を追加
    void add_edge(const int &u, const int &v){
        assert(u != v && (0 <= u && u < n) && (0 <= v && v < n));
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // HL分解を行い、その結果のマッピング realID -> hldID を返す
    vector<int> hld(int rootRealnode, int topnode){
        _dfs(rootRealnode, 0);  // 部分木のサイズを求める など
        _hld(rootRealnode, topnode); // HL分解
        return realid2hldid;
    }

    // 実ノード u, v の2点間のパスを求める. 計算量: O(log(n))
    // 返すのは HLD 上の ID. (区間クエリに適用するため)
    vector<pair<int, int>> query(int u, int v){
        vector<pair<int, int>> HLDIDs;
        // 同じ列状になるまで
        while(shallowRealnode[u] != shallowRealnode[v]){
            // それぞれの列の先頭のノードの深さ が 浅い方を u にする
            // これによって root の列にいるノードががさらに列を登らないようにする
            if(depthRealnode[shallowRealnode[u]] > depthRealnode[shallowRealnode[v]]){
                swap(u, v);
            }

            // 深い方は親をたどるので, [v, vの浅いノード] を答えに追加して, v を更新
            HLDIDs.push_back({realid2hldid[shallowRealnode[v]], realid2hldid[v]});
            v = parentRealnode[shallowRealnode[v]];
        }

        // 同じ列にきたので, 最後の要素を加える
        // 区間クエリに備えて first <= second となるようにする
        pair<int, int> last = {realid2hldid[u], realid2hldid[v]};
        if(last.first > last.second) swap(last.first, last.second);
        HLDIDs.push_back(last);
        return HLDIDs;
    }
};

template <class T>
class FenwickTree {

private:
    int _n;
    vector<T> data;

    T sum(int r) {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
    
public:
    FenwickTree() : _n(0) {}
    explicit FenwickTree(int n) : _n(n), data(n) {}

    void set(int p, T x) {
        assert(0 <= p && p < _n);
        T tmp = sum(p+1)-sum(p);
        add(p, x-tmp);
    }

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while(p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    // [l, r)
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

};


// verify: https://judge.yosupo.jp/problem/vertex_add_path_sum
int main(){
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    HeavyLightDecomposition hld(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        hld.add_edge(u, v);
    }
    vector<int> hldmap = hld.hld(0, 0);

    FenwickTree<ll> bit(n);
    rep(i, 0, n) bit.set(hldmap[i], a[i]); // HLD 上の ID で乗せる

    while(q--){
        int t; cin >> t;
        if(t == 0){
            int p;
            ll x; cin >> p >> x;
            p = hldmap[p];
            bit.add(p, x);
        }else{
            int u, v; cin >> u >> v;
            vector<pair<int, int>> path = hld.query(u, v);
            ll res = 0;
            for(auto [l, r]: path){
                res += bit.sum(l, r+1); // 閉区間であることに注意
            }
            cout << res << '\n';
        }
    }
    return 0;
}