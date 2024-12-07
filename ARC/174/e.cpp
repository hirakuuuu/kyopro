#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
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

using S = mint;
S op(S a, S b){ return a+b; }
S e(){ return 0; }

const int vmax = 300005; // ここは問題ごとに考慮が必要
mint fact[vmax], finv[vmax];
void initfact(){
	fact[0]= 1;
	for(int i = 1; i < vmax; i++) fact[i] = fact[i-1]*i; // 階乗の計算
	finv[vmax-1] = fact[vmax-1].inv();
	for(int i = vmax-2; i >=0; i--) finv[i] = finv[i+1]*(i+1); // 階乗の逆元
}
// nPk
mint perm(int n,int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 && k == 0) return 1;
	return fact[n]*finv[n-k];
}
// nCk
mint choose(int n,int k){
    if(n < 0 || k < 0 || n < k) return 0;
    if(n == 0 && k == 0) return 1;
	return fact[n]*finv[n-k]*finv[k];
}
// (a+b)!/(a!b!)
mint binom(int a,int b){
	return 0<=a&&0<=b?fact[a+b]*finv[a]*finv[b]:0;
}
// カタラン数（括弧列とか）
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}
// 重複組み合わせ
mint homogeneous(int n, int k){
    return choose(n+k-1, k);
}

int main(){
    initfact();
    int n, k; cin >> n >> k;
    vector<int> p(k), rev(n, k-1), in_p(n);
    rep(i, 0, k) cin >> p[i], p[i]--, rev[p[i]] = i, in_p[p[i]] = 1;
    
    vector<int> l(k);
    {
        SegmentTree<S, op, e> cnt(vector<S>(n, 1));
        rep(i, 0, k){
            l[i] = cnt.prod(0, p[i]).val();
            cnt.set(p[i], 0);
        }
    }

    SegmentTree<S, op, e> st1(k), st2(k); 
    rep(i, 0, k){
        st1.set(i, perm(n-1-i, k-1-i)*l[i]);
    }
    rep(i, 0, k){
        st2.set(i, (perm(n-1-i, k-1-i)-perm(n-2-i, k-1-i))*l[i]);
    }
    
    vector<mint> ans(n, st1.prod(0, k));
    SegmentTree<S, op, e> elm(k);
    rrep(i, n-1, 0){
        ans[i] -= st1.prod(0, rev[i]+1);
        ans[i] += st2.prod(0, rev[i]+1);
        ans[i] += elm.prod(0, rev[i]+1);

        if(in_p[i]) elm.set(rev[i], perm(n-rev[i]-2, k-rev[i]-1));
    }
    rep(i, 0, k){
        ans[p[i]] += 1;
    }
    rep(i, 0, n){
        cout << ans[i].val() << endl;
    }
    

    return 0;
}