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
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<int> l(n), r(n);
    rep(i, 0, n){
        cin >> a[i] >> l[i] >> r[i]; l[i]--;
    }
    vector<int> pos(n);
    rep(i, 0, n) pos[i] = i;
    LazySegmentTree<S, op, e, F, mapping, composition, id> lst(m);
    LazySegmentTree<S, op, e, F, mapping, composition, id> lst2(m);
    rep(i, 0, n){
        lst.apply(l[i], r[i], 1);
        lst2.apply(i, i+1, a[i]);
    }

    ll sum = 0;
    rep(i, 0, n){
        sum += (r[i]-l[i])*a[i];
        sum -= lst2.prod(l[i], r[i]).first;
    }
    // cout << sum << endl;

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y; x--, y--;
        int u, v; cin >> u >> v; u--;

        sum -= (r[x]-l[x])*a[x];
        sum += lst2.prod(l[x], r[x]).first;
        sum += lst.get(pos[x]).first*a[x];
        if(inr(l[x], pos[x], r[x])) sum -= a[x];
        // cout << sum << endl;

        lst.apply(l[x], r[x], -1);
        lst2.apply(pos[x], pos[x]+1, -a[x]);
        pos[x] = y;
        l[x] = u;
        r[x] = v;
        lst.apply(l[x], r[x], 1);
        lst2.apply(pos[x], pos[x]+1, a[x]);


        sum += (r[x]-l[x])*a[x];
        sum -= lst2.prod(l[x], r[x]).first;
        // cout << sum << endl;
        sum -= lst.get(pos[x]).first*a[x];
        // rep(i, 0, m){
        //     cout << lst.get(i).first << ' ';
        // }
        // cout << endl;
        if(inr(l[x], pos[x], r[x])) sum += a[x];

        cout << sum << endl;
    }

    return 0;
}