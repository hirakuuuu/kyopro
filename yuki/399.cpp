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

template<typename T>
struct HLDecomposition{
    int n, root;
    vector<vector<int>> to;
    vector<int> par;   // 根付き木の親
    vector<int> subsz; // 部分木のサイズ
    vector<int> in;    // 行きがけ順
    vector<int> head;  // 最も近い heavy なパス上の点

    HLDecomposition(int _n): n(_n), to(_n), par(_n), subsz(_n), in(_n), head(_n) {}

    void add_edge(int u, int v){
        to[u].push_back(v);
        to[v].push_back(u);
    }

    // 部分木のサイズを計算 and heavy な辺を to[v][0] に移動
    void dfs1(int pos, int pre){
        par[pos] = pre;
        subsz[pos] = 1;
        // heavy な辺を先頭に持っていく
        if(to[pos].size() && to[pos][0] == pre) swap(to[pos][0], to[pos].back());
        for(int i = 0; i < (int)to[pos].size(); i++){
            int nxt = to[pos][i];
            if(nxt == pre) continue;
            dfs1(nxt, pos);
            subsz[pos] += subsz[nxt];
            if(subsz[to[pos][0]] < subsz[nxt]) swap(to[pos][0], to[pos][i]);
        }
    }

    void dfs2(int pos, int pre, int &t){
        in[pos] = t++;
        for(auto nxt: to[pos]){
            if(nxt == pre) continue;
            head[nxt] = (to[pos][0] == nxt ? head[pos] : nxt);
            dfs2(nxt, pos, t);
        }
    }

    void init(int _root=0){
        root = _root;
        dfs1(root, -1);
        int t = 0;
        dfs2(root, -1, t);
    }

    // u-v パスの間にある辺に対応する列状の区間の集合 [l, r)
    // HLDにより個の個数が O(log n) に抑えられる
    vector<pair<int, int>> get_edge(int u, int v){
        vector<pair<int, int>> res;
        while(true){
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            res.emplace_back(in[head[v]], in[v]+1);
            v = par[head[v]];
        }
        if(in[u]+1 != in[v]+1) res.emplace_back(in[u]+1, in[v]+1);
        return res;
    }

    // u-v パスの間にある頂点に対応する列状の区間の集合 [l, r)
    // HLDにより個の個数が O(log n) に抑えられる
    vector<pair<int, int>> get_vertex(int u, int v){
        vector<pair<int, int>> res;
        while(true){
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            res.emplace_back(in[head[v]], in[v]+1);
            v = par[head[v]];
        }
        res.emplace_back(in[u], in[v]+1);
        return res;
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
using S = pair<ll, ll>;
S op(S a, S b) { return {a.first+b.first, a.second+b.second}; }
S e() { return {0LL, 1LL}; }
// 一次関数 a x + b によって恒等写像と代入を表現
using F = ll;
F id() { return 0; }
S mapping(F a, S x) { 
    return {x.first+a*x.second, x.second}; 
}
// a(b(x)) という包含関係
F composition(F a, F b) { 
    return a+b;
}



int main(){
    int n; cin >> n;
    HLDecomposition<int> g(n);
    rep(i, 0, n-1){
        int u, v; cin >> u >> v;
        u--, v--;
        g.add_edge(u, v);
    }
    g.init();

    LazySegmentTree<S, op, e, F, mapping, composition, id> lst(n);
    int q; cin >> q;
    ll ans = 0;
    while(q--){
        int a, b; cin >> a >> b;
        a--, b--;
        vector<pair<int, int>> vec = g.get_vertex(a, b);
        for(auto [l, r]: vec){
            lst.apply(l, r, 1);
            ans += lst.prod(l, r).first;
        }
    }
    cout << ans << endl;

    
    return 0;
}