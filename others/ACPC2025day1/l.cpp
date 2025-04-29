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


template <class T, T (*op)(T, T), T (*e)()> 
class SegmentTree {
    int _n, size, log;
    vector<T> d;
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
public:
    SegmentTree() : SegmentTree(0) {}
    explicit SegmentTree(int n) : SegmentTree(vector<T>(n, e())) {} // explicit で明示的に型を指定する
    explicit SegmentTree(const vector<T> &v) : _n(int(v.size())) {
        // sizeは_nを超える最小の2のべき乗
        size = 1;
        while(size < _n) size *= 2, log++; 

        // log は木の高さ（sizeの桁数）
        log = 0;
        while (!(size & (1 << log))) log++;

        d = vector<T>(2*size, e());
        for(int i = 0; i < _n; i++) d[size+i] = v[i];
        for(int i = size-1; i >= 1; i--){
            update(i);
        }
    }

    void set(int p, T x){
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    T get(int p) const {
        assert(0 <= p && p < _n);
        return d[p+size];
    }

    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        T sml = e(), smr = e();
        l += size;
        r += size;

        while(l < r){
            if(l&1) sml = op(sml, d[l++]);
            if(r&1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    T all_prod() const {return d[1]; };

    // f(op(a[l], a[l + 1], ..., a[r - 1])) = trueとなる最大のｒ
    template <bool (*f)(T)> int max_right(int l) const {
        return max_right(l, [](T x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        T sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
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

    // f(op(a[l], a[l + 1], ..., a[r - 1])) = true となる最小の l
    template <bool (*f)(T)> int min_left(int r) const {
        return min_left(r, [](T x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        T sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
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

using S = uint64_t;
S op(S a, S b) {
    return a^b;
}
S e() {
    return 0;
}


int main(){
    random_device seed_gen;
    mt19937_64 engine(seed_gen());
    vector<uint64_t> hash(1000005);
    rep(i, 0, 1000005){
        hash[i] = engine();
    }

    int n; cin >> n;
    vector<vector<pair<int, uint64_t>>> g(n);
    vector<int> u(n-1), v(n-1);
    rep(i, 0, n-1){
        cin >> u[i] >> v[i]; u[i]--, v[i]--;
        int f; cin >> f;
        // cout << f << ' ' << hash[f] << endl;
        g[u[i]].push_back({v[i], hash[f]});
        g[v[i]].push_back({u[i], hash[f]});
    }

    vector<uint64_t> w(n);
    auto dfs = [&](auto self, int pos, int pre) -> void {
        for(auto [nxt, f]: g[pos]){
            if(nxt == pre) continue;
            w[nxt] = f;
            self(self, nxt, pos);
        }
    };
    dfs(dfs, 0, -1);

    HLDecomposition<int> hld(n);
    rep(i, 0, n-1){
        hld.add_edge(u[i], v[i]);
    }

    hld.init();
    SegmentTree<S, op, e> st(n);
    rep(i, 0, n){
        vector<pair<int, int>> vec = hld.get_vertex(i, i);
        // cout << vec[0].first << ' ' << vec[0].second << endl;
        // st.set(vec[0].first, w[i]);
        st.set(vec[0].first, st.get(vec[0].first)^w[i]);
    }

    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b; a--, b--;
        vector<pair<int, int>> vec = hld.get_edge(a, b);
        uint64_t tmp = 0;
        for(auto [l, r]: vec){
            // cout << "###" << l << ' ' << r << endl;
            // cout << st.prod(l, r) << endl;
            tmp ^= st.prod(l, r);
        }
        // cout << tmp << endl;
        if(tmp == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }




    
    return 0;
}