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
// using mint2 = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

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
struct S {
    ll cusum;
    ll resum;
    ll sum;
    ll sz;
    S(ll cusum=0, ll resum=0, ll sum=0, ll sz=0): cusum(cusum), resum(resum), sum(sum), sz(sz) {}
};
S op(S a, S b) { 
    return S((a.cusum+b.sz*(a.sum-a.sz))+b.cusum, a.resum+(b.resum+(b.sum-b.sz)*a.sz), a.sum+b.sum, a.sz+b.sz);
}
S e() { return S(0, 0, 0, 0); }
// 一次関数 a x + b によって恒等写像と代入を表現
using F = ll;
F id() { return -1; }
S mapping(F a, S x) { 
    if(a == id()) return x;
    return S((a-1)*(x.sz)*(x.sz+1)/2, (a-1)*(x.sz)*(x.sz+1)/2, a*x.sz, x.sz);
}
// a(b(x)) という包含関係
F composition(F a, F b) { 
    if(a == id()) return b;
    return a;
}


int main(){
    int n; cin >> n;
    vector<ll> x(n+1);
    rep(i, 1, n+1) cin >> x[i], x[i] += IINF;
    int q; cin >> q;
    LazySegmentTree<S, op, e, F, mapping, composition, id> lst(n);
    rep(i, 0, n){
        lst.set(i, S(x[i+1]-x[i]-1, x[i+1]-x[i]-1, x[i+1]-x[i], 1));
    }

    ll ans = 0;
    while(q--){
        int t; cin >> t;
        ll g; cin >> g;
        g += IINF;
        // cout << lst.prod(0, t).sum << endl;
        if(g <= lst.prod(0, t).sum){
            // 左に移動
            // [l, t) の範囲の高橋君を動かす
            int l = -1;
            {
                int ng = -1, ok = t-1;
                while(ok-ng > 1){
                    int mid = (ok+ng)/2;
                    if(lst.prod(0, mid+1).sum <= g-(t-1-mid)) ng = mid;
                    else ok = mid;
                }
                l = ok;
            }
            // コストを計算
            // cout << l+1 << ' ' << t << endl;
            // cout << lst.prod(l+1, t).cusum << ' ' << lst.prod(l+1, t).resum << ' ' << lst.prod(l+1, t).sum << ' ' << lst.prod(l+1, t).sz << endl;
            // cout << lst.prod(l, t).cusum << ' ' << lst.prod(l, t).resum << ' ' << lst.prod(l, t).sum << ' ' << lst.prod(l, t).sz << endl;

            ans += lst.prod(l+1, t).cusum;
            // cout << ans << endl;
            ll pos = lst.prod(0, l+1).sum+(t-l-1);
            ans += (pos-g)*(t-l);

            // セグ木を更新
            ll r = lst.prod(0, min(n, t+1)).sum;
            lst.apply(l, l+1, (g-(t-l-1))-lst.prod(0, l).sum);
            lst.apply(l+1, t, 1);
            if(t != n) lst.apply(t, t+1, r-g);

            // rep(i, 0, n){
            //     cout << lst.prod(0, i+1).sum << ' ';
            // }
            // cout << endl;
        }else{
            // 左に移動
            // [t, r] の範囲の高橋君を動かす
            int r = n;
            {
                int ng = n+1, ok = t;
                while(ng-ok > 1){
                    int mid = (ok+ng)/2;
                    if(g+(mid-t-1) <= lst.prod(0, mid).sum) ng = mid;
                    else ok = mid;
                }
                r = ok;
            }
            // // コストを計算
            // cout << t << ' ' << r << endl;
            // cout << lst.prod(t, r).cusum << ' ' << lst.prod(t, r).sum << ' ' << lst.prod(t, r).sz << endl;

            ans += lst.prod(t, r).resum;
            ll pos = lst.prod(0, r).sum-(r-t);
            ans += (g-pos)*(r-t+1);

            // セグ木を更新
            ll l = lst.prod(0, t-1).sum;
            if(r != n) lst.apply(r, r+1, lst.prod(0, r+1).sum-(g+(r-t)));
            lst.apply(t, r, 1);
            lst.apply(t-1, t, g-l);

            // rep(i, 0, n){
            //     cout << lst.prod(0, i+1).sum << ' ';
            // }
            // cout << endl;
            // rep(i, 0, n){
            //     cout << lst.prod(i, i+1).resum << ' ';
            // }
            // cout << endl;
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
    
    return 0;
}