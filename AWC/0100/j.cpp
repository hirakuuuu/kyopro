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


template <class T, T (*op)(T, T), T (*e)(), class F, T (*mapping)(F, T), F (*composition)(F, F), F (*id)()> 
class LazySegmentTree {
    int _n, size, log;
    vector<T> d;
    vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

    void all_apply(int k, F f){
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }

    void push(int k){
        all_apply(2*k, lz[k]);
        all_apply(2*k+1, lz[k]);
        lz[k] = id();
    }

public:
    LazySegmentTree() : LazySegmentTree(0) {}
    explicit LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, e())) {} // explicit で明示的に型を指定する
    explicit LazySegmentTree(const vector<T> &v) : _n(int(v.size())) {
        // sizeは_nを超える最小の2のべき乗
        size = 1;
        while(size < _n) size *= 2, log++; 

        // log は木の高さ（sizeの桁数）
        log = 0;
        while (!(size & (1 << log))) log++;

        d = vector<T>(2*size, e());
        lz = vector<F>(size, id());

        for(int i = 0; i < _n; i++) d[size+i] = v[i];
        for(int i = size-1; i >= 1; i--){
            update(i);
        }
    }

    void set(int p, T x){
        assert(0 <= p && p < _n);
        p += size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    T get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for(int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }


    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return e();

        l += size;
        r += size;

        for(int i = log; i >= 1; i--){
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r-1) >> i);
        }
        
        T sml = e(), smr = e();
        while(l < r){
            if(l&1) sml = op(sml, d[l++]);
            if(r&1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    T all_prod() {return d[1]; }

    void apply(int p, F f){
        assert(0 <= p && p < _n);
        p += size;
        for(int i = log; i >= 1; i--) push(p >> i); 
        d[p] = mapping(f, d[p]);
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    void apply(int l, int r, F f){
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return;

        l += size;
        r += size;

        for(int i = log; i >= 1; i--){
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r-1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while(l < r){
                if(l&1) all_apply(l++, f);
                if(r&1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for(int i = 1; i <= log; i++){
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r-1) >> i);
        }
    }

    // f(op(a[l], a[l + 1], ..., a[r - 1])) = trueとなる最大のｒ
    template <bool (*g)(T)> int max_right(int l) {
        return max_right(l, [](T x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        T sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(T)> int min_left(int r) {
        return min_left(r, [](T x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        T sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};

// 遅延セグメント木の準備
using S =  ll;
S op(S a, S b) { return min(a, b); }
S e() { return 9e18; }
// 一次関数 a x + b によって恒等写像と代入を表現
using F = ll;
S mapping(F a, S x) { return a+x; }
// a(b(x)) という包含関係
F composition(F a, F b) { return a+b; }
F id() { return 0LL; }

template<typename T> 
struct LCA {
    int n, root, lg;
    vector<vector<int>> to;
    vector<vector<T>> cost;
    vector<int> depth;
    vector<T> cost_to_root;
    vector<vector<int>> par;
    
    LCA(int _n): n(_n), to(_n), cost(_n), depth(_n), cost_to_root(_n) {
        lg = 0; // ダブリングで 2^lg まで持つ
        while((1<<lg) < n) lg++;
        par = vector<vector<int>>(n+1, vector<int>(lg, n));
    }
    
    void add_edge(int u, int v, T c=1){
        to[u].push_back(v), cost[u].push_back(c);
        to[v].push_back(u), cost[v].push_back(c);
    }

    void dfs(int pos, int dep=0, T c=0, int pre=-1){
        if(pre != -1) par[pos][0] = pre;
        depth[pos] = dep;
        cost_to_root[pos] = c;
        for(int i = 0; i < (int)to[pos].size(); i++){
            int nxt = to[pos][i];
            if(nxt == pre) continue;
            dfs(nxt, dep+1, c+cost[pos][i], pos);
        }
    }

    // 各頂点の 2^i (0 <= i <= lg) 個上の頂点をダブリングで求める
    void init(int _root=0){
        root = _root;
        dfs(root);
        for(int i = 0; i < lg-1; i++){
            for(int v = 0; v < n; v++){
                par[v][i+1] = par[par[v][i]][i];
            }
        }
    }

    // LCA
    int lca(int u, int v){
        if(depth[u] > depth[v]) swap(u, v);
        int gap = depth[v]-depth[u];
        
        // 深い方 (v) を浅い方 (u) と同じ深さまで移動した頂点にする
        for(int i = lg-1; i >= 0; i--){
            int len = 1<<i;
            if(gap >= len){
                gap -= len;
                v = par[v][i];
            }
        }

        if(u == v) return u; // 同じ頂点なら u が LCA
        
        // LCAの1つ下まで登る
        for(int i = lg-1; i >= 0; i--){
            int nu = par[u][i], nv = par[v][i];
            if(nu != nv) u = nu, v = nv;
        }
        return par[u][0];
    }
    int operator()(int u, int v){
        return lca(u, v);
    }

    // 辺の本数
    int length(int u, int v){
        int w = lca(u, v);
        return depth[u]+depth[v]-depth[w]*2;
    }
    // 重み付き距離
    T dist(int u, int v){
        int w = lca(u, v);
        return cost_to_root[u]+cost_to_root[v]-cost_to_root[w]*2;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> w(n);
    w[0] = INF;
    HeavyLightDecomposition hld(n);
    LCA<int> lca(n);
    rep(i, 1, n){
        int p; cin >> p; p--;
        cin >> w[i];
        hld.add_edge(p, i);
        lca.add_edge(p, i);
    }

    lca.init();
    vector<int> hldmap = hld.hld(0, 0);
    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(n);    
    rep(i, 0, n) seg.set(hldmap[i], w[i]); // HLD 上の ID で乗せる


    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v; u--, v--;
        if(u == v) continue;
        vector<pair<int, int>> path = hld.query(u, v);
        int x = lca.lca(u, v);
        x = hldmap[x];
        for(auto [l, r]: path){
            if(inr(l, x, r+1)){
                seg.apply(l, x, 1);
                seg.apply(x+1, r+1, 1);
            }else{
                seg.apply(l, r+1, 1); // 閉区間であることに注意
            }
            // cout << l << ' ' << r << endl;
        }
    }

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b; a--, b--;
        if(a == b){
            cout << 0 << endl;
        }else{
            ll ans = INF;
            vector<pair<int, int>> path = hld.query(a, b);
            int x = lca.lca(a, b);
            x = hldmap[x];
            for(auto [l, r]: path){
                if(inr(l, x, r+1)){
                    chmin(ans, seg.prod(l, x));
                    chmin(ans, seg.prod(x+1, r+1));
                }else{
                    chmin(ans, seg.prod(l, r+1));
                }
            }
            cout << ans << endl;
        }
    }




    
    return 0;
}