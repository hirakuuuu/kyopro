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
constexpr ll INF = 9e18;

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

using S = ll;
S op(S a, S b) {
    return a+b;
}
S e() {
    return 0LL;
}


int main(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    int q; cin >> q;
    vector<tuple<int, ll, ll>> queri(q);
    vector<ll> c = a;
    rep(i, 0, q){
        int t;
        ll x, y = 0; cin >> t;
        if(t == 1){
            cin >> x >> y;
            c.push_back(y);
            x--;
        }else if(t == 2){
            cin >> x >> y;
            x--;
        }else{
            cin >> x;
        }
        queri[i] = {t, x, y};
    }
    
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    int m = (int)c.size();
    SegmentTree<S, op, e> sum(m), cnt(m);
    rep(i, 0, n){
        int p = lower_bound(c.begin(), c.end(), a[i])-c.begin();
        sum.add(p, a[i]*b[i]);
        cnt.add(p, b[i]);
    }
    rep(i, 0, q){
        auto [t, x, y] = queri[i];
        if(t == 1){
            int cur = lower_bound(c.begin(), c.end(), a[x])-c.begin();
            int nxt = lower_bound(c.begin(), c.end(), y)-c.begin();
            sum.add(cur, -a[x]*b[x]); cnt.add(cur, -b[x]);
            sum.add(nxt, y*b[x]); cnt.add(nxt, b[x]);
            a[x] = y;
        }else if(t == 2){
            int cur = lower_bound(c.begin(), c.end(), a[x])-c.begin();
            sum.add(cur, -a[x]*(b[x]-y)); cnt.add(cur, -(b[x]-y));
            b[x] = y;
        }else{
            if(cnt.all_prod() < x){
                cout << -1 << endl;
            }else{
                int ok = 0, ng = m;
                while(ng-ok > 1){
                    int mid = (ok+ng)/2;
                    if(cnt.prod(mid, m) < x) ng = mid;
                    else ok = mid;
                }
                auto ans = sum.prod(ok, m);
                ans -= c[ok]*(cnt.prod(ok, m)-x);
                cout << ans << endl;
            }
        }
    }


    
    return 0;
}