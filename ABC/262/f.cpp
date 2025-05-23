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
    
    void apply(int p, T x){
        set(p, op(x, d[p+size]));
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

using S = pair<int, int>;
S op(S a, S b){ return min(a, b); }
S e(){ return {IINF, IINF}; }

int main(){
    int n, k; cin >> n >> k;
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];

    // 前から k+1 個以内にある要素か，
    // 後ろから k 個以内にある要素は先頭に持っていける
    // その中で最も小さい値が先頭になるべき
    int mii = IINF, miv = IINF;
    rep(i, 0, n){
        if(i <= k || n-k <= i){
            if(miv > p[i]){
                miv = p[i], mii = i;
            }
        }
    }

    // 前から削除して先頭に持っていける場合
    vector<int> f = {IINF};
    if(mii <= k){
        f.clear();
        vector<int> q = p;
        SegmentTree<S, op, e> st(n);
        rep(i, 0, n) st.set(i, {q[i], i});
        int l = mii, rest = k-mii;
        // cout << l << ' ' << rest << endl;
        while(l < n && rest){
            // cout << l << ' ' << l+rest+1 << endl;
            auto [mi, id] = st.prod(l, min(n, l+rest+1));
            f.push_back(mi);
            rest -= id-l;
            l = id+1;
        }
        if(rest){
            while(rest) f.pop_back(), rest--;
        }else{
            rep(i, l, n) f.push_back(q[i]);
        }
    }

    // 後ろから先頭に持っていける場合
    vector<int> g = {IINF};
    if(n-k <= mii){
        // n-mii 個までは，残すにも消すにもコストが 1 かかる
        // それより後ろは，消すときにコストが 1 かかる
        g.clear();
        vector<int> q = p;
        rotate(q.begin(), q.begin()+mii, q.end());
        SegmentTree<S, op, e> st(n);
        rep(i, 0, n) st.set(i, {q[i], i});
        int l = n-mii, rest = k-(n-mii);
        // cout << l << ' ' << rest << endl;
        while(l < n && rest){
            // cout << l << ' ' << l+rest+1 << endl;
            auto [mi, id] = st.prod(l, min(n, l+rest+1));
            g.push_back(mi);
            rest -= id-l;
            l = id+1;
        }
        if(rest){
            while(rest) g.pop_back(), rest--;
        }else{
            rep(i, l, n) g.push_back(q[i]);
        }
        reverse(g.begin(), g.end());
        rrep(i, n-1-mii, 0){
            if(g.empty()) continue;
            if(q[i] < g.back()) g.push_back(q[i]); 
        }
        reverse(g.begin(), g.end());
    }
    // for(auto ff: f){
    //     cout << ff << ' ';
    // }
    // cout << endl;
    // for(auto gg: g){
    //     cout << gg << ' ';
    // }
    // cout << endl;
    vector<int> ans = min(f, g);
    for(auto aa: ans){
        cout << aa << ' ';
    }
    cout << endl;
    


    
    return 0;
}