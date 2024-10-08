#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint1 = modint1000000007;
using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

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

using S1 = mint1;
using S2 = mint2;
S1 op1(S1 a, S1 b) {
    return a*b;
}

S1 e1() {
    return 1;
}
S2 op2(S2 a, S2 b) {
    return a*b;
}

S2 e2() {
    return 1;
}

// 0ならば素数, 0でないなら最小の素因数
vector<int> erat(10000005);
void init_e(){
    rep(i, 2, sqrt(10000005)){
        if(erat[i] == 0){
            for(ll j = i*i; j < 10000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

int main(){
    init_e();
    vector<int> p;
    int r = 2;
    while(p.size() <= 200005){
        if(erat[r] == 0) p.push_back(r);
        r++;
    }

    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i]--;
    }
    rep(i, 0, n){
        cin >> b[i];
        b[i]--;
    }

    SegmentTree<S1, op1, e1> st1_a(n), st1_b(n);
    SegmentTree<S2, op2, e2> st2_a(n), st2_b(n);
    rep(i, 0, n){
        st1_a.set(i, mint1(p[a[i]]));
        st2_a.set(i, mint2(p[a[i]]));
        st1_b.set(i, mint1(p[b[i]]));
        st2_b.set(i, mint2(p[b[i]]));
    }

    while(q--){
        int l, r, L, R; cin >> l >> r >> L >> R;
        l--, L--;
        if(r-l != R-L){
            cout << "No" << endl;
        }else{
            // cout << st1_a.prod(l, r).val() << ' ' << st1_b.prod(L, R).val() << endl;
            // cout << st2_a.prod(l, r).val() << ' ' << st2_b.prod(L, R).val() << endl;
            if(st1_a.prod(l, r) == st1_b.prod(L, R)
            && st2_a.prod(l, r) == st2_b.prod(L, R)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    

    
    return 0;
}