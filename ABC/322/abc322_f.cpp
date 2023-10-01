#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc322/tasks/abc322_f

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

// S: 各要素および区間取得結果の型
struct S {
    bool all0, all1;
    int left0, max0, right0;
    int left1, max1, right1;

    S(): all0(false), all1(false), left0(0), max0(0), right0(0), left1(0), max1(0), right1(0) {}; 
    S(int x): all0(x == 0), all1(x == 1), left0(x == 0), max0(x == 0), right0(x == 0), left1(x == 1), max1(x == 1), right1(x == 1) {}; 
};
// F: 操作（写像）を表す値の型
struct F {
    bool x;
    F(bool x_): x(x_) {};
};

// op: 区間取得をどのような演算で行うか（区間min → min）
S op(S a, S b) {
    S res;
    res.all0 = a.all0 && b.all0;
    res.all1 = a.all1 && b.all1;
    res.left0 = a.all0 ? a.max0+b.left0 : a.left0;
    res.max0 = max({a.max0, b.max0, a.right0+b.left0});
    res.right0 = b.all0 ? a.right0+b.max0 : b.right0;
    res.left1 = a.all1 ? a.max1+b.left1 : a.left1;
    res.max1 = max({a.max1, b.max1, a.right1+b.left1});
    res.right1 = b.all1 ? a.right1+b.max1 : b.right1;
    return res;
};
// 単位元
S e() { return S(); };

// mapping: 操作を各ノードが持つdataの値に対して作用させる関数（ｘを加算）
S mapping(F a, S x) {
    if(a.x){
        swap(x.all0, x.all1);
        swap(x.left0, x.left1);
        swap(x.max0, x.max1);
        swap(x.right0, x.right1);
    }
    return x;
};
// composition: 操作をためているlazyに、新しい操作を追加する関数（可換でない場合は順番に注意）
F composition(F a, F b) {
    a.x ^= b.x;
    return a;
}
// 恒等写像
F id() { return F(false); }


int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<S> a(n);
    rep(i, 0, n) a[i] = S(s[i]-'0');
    LazySegmentTree<S, op, e, F, mapping, composition, id> lst(a);
    while(q--){
        int c, l, r; cin >> c >> l >> r;
        l--;
        if(c == 1){
            lst.apply(l, r, F(true));
        }else if(c == 2){
            cout << lst.prod(l, r).max1 << endl;
        }
    }
    return 0;
}