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

    void add(int p, T x){
        assert(0 <= p && p < _n);
        p += size;
        d[p] += x;
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

struct S {
    int mx;
    int len;
    char cl;
    int len_l;
    char cr;
    int len_r;
};
S op(S a, S b) {
    if(a.len == 0){
        return b;
    }
    if(b.len == 0){
        return a;
    }
    S c;
    c.len = a.len+b.len;
    c.mx = max(a.mx, b.mx);
    if(a.cr == b.cl) chmax(c.mx, a.len_r+b.len_l);
    c.cl = a.cl;
    c.len_l = a.len_l;
    c.cr = b.cr;
    c.len_r = b.len_r;
    if(a.len == a.len_l && a.cl == b.cl){
        c.len_l = a.len_l+b.len_l;
    }
    if(b.len == b.len_r && b.cr == a.cr){
        c.len_r = b.len_r+a.len_r;
    }
    chmax(c.mx, max(c.len_l, c.len_r));
    return c;
}

S e() {
    return S();
}

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<S> init(n);
    rep(i, 0, n){
        S tmp;
        tmp.mx = tmp.len = tmp.len_l = tmp.len_r = 1;
        tmp.cl = tmp.cr = s[i];
        init[i] = tmp;
    }
    SegmentTree<S, op, e> st(init);

            // cout << st.prod(0, n).mx << ' ' << st.prod(0, n).len_l << ' ' << endl;

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i; cin >> i; i--;
            char x; cin >> x;

            S tmp;
            tmp.mx = tmp.len = tmp.len_l = tmp.len_r = 1;
            tmp.cl = tmp.cr = x;
            st.set(i, tmp);
        }else{
            int l, r; cin >> l >> r; l--;
            cout << st.prod(l, r).mx << endl;
            // cout << st.prod(l, r).cl << ' ' << st.prod(l, r).len_l << endl;
            // cout << st.prod(l, r).cr << ' ' << st.prod(l, r).len_r << endl;
            // cout << st.prod(l, r).len << endl;
        }
    }
    
    return 0;
}