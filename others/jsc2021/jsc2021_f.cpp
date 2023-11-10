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
// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_f

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

using S = pair<ll, ll>;
S op(S a, S b) {
    return {a.first+b.first,  a.second+b.second};
}

S e() {
    return {0LL, 0LL};
}

// bool f(int v){
//     return v < target;
// }

// 座標圧縮
void comp(vector<ll>&a){
  set<ll>s(a.begin(),a.end());
  map<ll,ll>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}


int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<ll> a(n+1), b(m+1);
    SegmentTree<pair<ll, ll>, op, e> st_a(q+5), st_b(q+5);
    st_a.set(0, {0, n});
    st_b.set(0, {0, m});
    ll sum = 0;
    vector<ll> t(q), x(q), y(q);
    rep(i, 0, q) cin >> t[i] >> x[i] >> y[i];
    map<ll, ll> yi;
    vector<ll> y_ = y;
    y_.push_back(0LL);
    sort(y_.begin(), y_.end());
    y_.erase(unique(y_.begin(), y_.end()), y_.end());
    rep(i, 0, y_.size()){
        yi[y_[i]]= i;
    }

    rep(i, 0, q){
        if(t[i] == 1){

            auto [s1, d1] = st_b.prod(0, yi[a[x[i]]]+1);
            auto [s2, d2] = st_b.prod(0, yi[y[i]]+1);
            sum -= d1*a[x[i]]+s2-s1;
            sum += d2*y[i];

            st_a.set(yi[a[x[i]]], {st_a.get(yi[a[x[i]]]).first-a[x[i]], st_a.get(yi[a[x[i]]]).second-1});
            st_a.set(yi[y[i]], {st_a.get(yi[y[i]]).first+y[i], st_a.get(yi[y[i]]).second+1});
            a[x[i]] = y[i];
        }else if(t[i] == 2){

            auto [s1, d1] = st_a.prod(0, yi[b[x[i]]]+1);
            auto [s2, d2] = st_a.prod(0, yi[y[i]]+1);
            sum -= d1*b[x[i]]+s2-s1;
            sum += d2*y[i];

            st_b.set(yi[b[x[i]]], {st_b.get(yi[b[x[i]]]).first-b[x[i]], st_b.get(yi[b[x[i]]]).second-1});
            st_b.set(yi[y[i]], {st_b.get(yi[y[i]]).first+y[i], st_b.get(yi[y[i]]).second+1});
            b[x[i]] = y[i];
        }
        cout << sum << endl;
    }



    
    
    return 0;
}