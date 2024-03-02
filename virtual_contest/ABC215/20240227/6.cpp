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
// 

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

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return -1;
}

int op_mi(int a, int b) {
    return min(a, b);
}

int e_mi() {
    return IINF;
}

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n), sx(n);
    vector<pair<int, int>> xy(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        sx[i] = x[i];
        xy[i] = {x[i], y[i]};
    }
    sort(sx.begin(), sx.end());
    sx.erase(unique(sx.begin(), sx.end()), sx.end());
    sort(xy.begin(), xy.end());
    map<int,int>d;
    int cnt=0;
    for(auto xx:sx)d[xx]=cnt++;
    SegmentTree<int, op, e> mx(cnt);
    SegmentTree<int, op_mi, e_mi> mi(cnt);
    rep(i, 0, n){
        int tmp = mx.get(d[x[i]]);
        mx.set(d[x[i]], max(tmp, y[i]));
        tmp = mi.get(d[x[i]]);
        mi.set(d[x[i]], min(tmp, y[i]));
    }

    int ok = 0, ng = 2e9;
    while(ng-ok > 1){
        int mid = (ok+ng)/2;
        bool f = false;
        rep(i, 0, n){
            int pos = lower_bound(sx.begin(), sx.end(), x[i]+mid)-sx.begin();
            if(pos < sx.size() && mx.prod(d[sx[pos]], cnt) >= y[i]+mid) f = true;
            if(pos < sx.size() && mi.prod(d[sx[pos]], cnt) <= y[i]-mid) f = true;
            pos = upper_bound(sx.begin(), sx.end(), x[i]-mid)-sx.begin();
            if(pos > 0 && mx.prod(0, d[sx[pos-1]]+1) >= y[i]+mid) f = true;
            if(pos > 0 && mi.prod(0, d[sx[pos-1]]+1) <= y[i]-mid) f = true;
        }
        if(f) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;






    
    return 0;
}