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
struct S{
    vector<ll> cnt;
    vector<ll> inv;
    S(int n=3): cnt(n), inv(n){};
};
S op(S a, S b) {
    S c;
    rep(i, 0, 3){
        c.cnt[i] = a.cnt[i]+b.cnt[i];
        c.inv[i] = a.inv[i]+b.inv[i];
    }
    c.inv[0] += a.cnt[1]*b.cnt[0];
    c.inv[1] += a.cnt[2]*b.cnt[1];
    c.inv[2] += a.cnt[2]*b.cnt[0];

    return c;
}

S e() {
    return S();
}

// 一次関数 a x + b によって恒等写像と代入を表現
using F = vector<int>;
F id() { return {-1, -1, -1}; }
S mapping(F a, S x) { 
    if(a == id()) return x;
    S nx;
    rep(i, 0, 3){
        nx.cnt[a[i]] += x.cnt[i];
    }
    if(a[0] == 0 && a[1] == 1){
        nx.inv[0] += x.inv[0];
    }else if(a[0] == 1 && a[1] == 2){
        nx.inv[1] += x.inv[0];
    }else if(a[0] == 0 && a[1] == 2){
        nx.inv[2] += x.inv[0];
    }else if(a[0] == 1 && a[1] == 0){
        nx.inv[0] += x.cnt[0]*x.cnt[1]-x.inv[0];
    }else if(a[0] == 2 && a[1] == 1){
        nx.inv[1] += x.cnt[0]*x.cnt[1]-x.inv[0];
    }else if(a[0] == 2 && a[1] == 0){
        nx.inv[2] += x.cnt[0]*x.cnt[1]-x.inv[0];
    }

    if(a[1] == 0 && a[2] == 1){
        nx.inv[0] += x.inv[1];
    }else if(a[1] == 1 && a[2] == 2){
        nx.inv[1] += x.inv[1];
    }else if(a[1] == 0 && a[2] == 2){
        nx.inv[2] += x.inv[1];
    }else if(a[1] == 1 && a[2] == 0){
        nx.inv[0] += x.cnt[1]*x.cnt[2]-x.inv[1];
    }else if(a[1] == 2 && a[2] == 1){
        nx.inv[1] += x.cnt[1]*x.cnt[2]-x.inv[1];
    }else if(a[1] == 2 && a[2] == 0){
        nx.inv[2] += x.cnt[1]*x.cnt[2]-x.inv[1];
    }


    if(a[0] == 0 && a[2] == 1){
        nx.inv[0] += x.inv[2];
    }else if(a[0] == 1 && a[2] == 2){
        nx.inv[1] += x.inv[2];
    }else if(a[0] == 0 && a[2] == 2){
        nx.inv[2] += x.inv[2];
    }else if(a[0] == 1 && a[2] == 0){
        nx.inv[0] += x.cnt[0]*x.cnt[2]-x.inv[2];
    }else if(a[0] == 2 && a[2] == 1){
        nx.inv[1] += x.cnt[0]*x.cnt[2]-x.inv[2];
    }else if(a[0] == 2 && a[2] == 0){
        nx.inv[2] += x.cnt[0]*x.cnt[2]-x.inv[2];
    }


    return nx; 
}
// a(b(x)) という包含関係
F composition(F a, F b) { 
    if(a == id()) return b;
    if(b == id()) return a;
    F c(3);
    rep(i, 0, 3){
        c[i] = a[b[i]];
    }
    return c;
}

int main(){

    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n);
    vector<S> init(n);
    rep(i, 0, n){
        cin >> a[i];
        init[i].cnt[a[i]]++;
    }
    LazySegmentTree<S, op, e, F, mapping, composition, id> lst(init);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r; l--;
            ll ans = 0;
            rep(i, 0, 3) ans += lst.prod(l, r).inv[i];
            cout << ans << endl;
        }else{
            int l, r; cin >> l >> r; l--;
            F b(3);
            rep(i, 0, 3) cin >> b[i];
            lst.apply(l, r, b);
        }
    }
    
    return 0;
}