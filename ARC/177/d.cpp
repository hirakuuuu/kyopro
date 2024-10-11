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

using S = ll;
S op(S a, S b) { return min(a, b); }
S e() { return INF; }
bool f(S x){ return x == e(); }


int main(){
    ll n, h; cin >> n >> h;
    vector<ll> x(n);
    rep(i, 0, n) cin >> x[i];
    vector<int> x_id(n), rev_x_id(n);
    iota(x_id.begin(), x_id.end(), 0);
    sort(x_id.begin(), x_id.end(), [&](auto i, auto j){ return x[i] < x[j]; });
    rep(i, 0, n) rev_x_id[x_id[i]] = i;
    // 隣接した電柱間の距離が H 以下のグループに分ける
    vector<vector<int>> g;
    vector<int> g_id(n); // 何番目のグループか
    vector<int> g_cnt(n); // グループの左から何番目か
    g.push_back({}); g.back().push_back(x_id[0]);
    g_id[x_id[0]] = 0, g_cnt[x_id[0]] = 0;
    rep(i, 1, n){
        if(x[x_id[i]]-x[x_id[i-1]] > h) g.push_back({});
        g.back().push_back(x_id[i]);
        g_id[x_id[i]] = (int)g.size()-1;
        g_cnt[x_id[i]] = (int)g.back().size()-1;
    }
    int m = (int)g.size();

    // 電柱 i から距離 H 以下の電柱であって, 番号が i 未満である左右の電柱を求める
    vector<ll> l(n), r(n); // g_cnt の値を入れる
    SegmentTree<S, op, e> st(n);
    rep(i, 0, n){
        l[i] = st.min_left<f>(rev_x_id[i])-1;
        // cout << l[i] << ' ';
        if(l[i] != -1 && g_id[st.get(l[i])] == g_id[i]) l[i] = g_cnt[st.get(l[i])];
        else l[i] = -1;

        r[i] = st.max_right<f>(rev_x_id[i]);
        // cout << r[i] << ' ';
        if(r[i] != n && g_id[st.get(r[i])] == g_id[i]) r[i] = g_cnt[st.get(r[i])];
        else r[i] = n;
        st.set(rev_x_id[i], i);
        // cout << i << ' ' << l[i] << ' ' << r[i] << endl;
        // rep(j, 0, n){
        //     cout << st.get(j) << ' ';
        // }
        // cout << endl;
    }

    mint ans = mint(2).pow(n);
    vector<mint> not_fall(n); // 電柱 t が t-1 回目の地震までで倒れていない確率
    vector<mint> prob(m);
    vector<int> cnt(m); // グループの何番目まで見たか（index）
    int not_zero = 0; // 全部倒れる確率が 0 でなくなったグループの個数
    rep(i, 0, n){
        // i が倒れていない確率
        not_fall[i] = 1;
        if(l[i] != -1 && r[i] != n){
            if(g[g_id[i]][l[i]] < g[g_id[i]][r[i]]) not_fall[i] *= (not_fall[g[g_id[i]][r[i]]])/2;
            else not_fall[i] *= (not_fall[g[g_id[i]][l[i]]])/2;
        }else if(l[i] != -1){
            not_fall[i] *= (not_fall[g[g_id[i]][l[i]]])/2;
        }else if(r[i] != n){
            not_fall[i] *= (not_fall[g[g_id[i]][r[i]]])/2;
        }
        // cout << i << ' ' << (not_fall[i]*mint(2).pow(n)).val() << endl;
        // l[i], r[i]
        mint p = not_fall[i];
        mint tmp = 0;
        // i が右に倒れて、すべて倒れた状態になるかどうか
        if(g_cnt[i] == 0 || (l[i] != -1 && g_cnt[i]-l[i] == 1)){
            tmp += p/2;
        }
        // i が右に倒れて、すべて倒れた状態になるかどうか
        if(g_cnt[i] == (int)g[g_id[i]].size()-1 || (r[i] != n && r[i]-g_cnt[i] == 1)){
            tmp += p/2;
        }
        mint pre = prob[g_id[i]];
        // cout << pre.val() << ' ' << tmp.val() << ' ' << ans.val() << not_zero <<  endl;
        if(tmp != 0){
            if(pre == 0) not_zero++;
            prob[g_id[i]] += tmp;
        }
        if(not_zero == m){
            if(pre == 0){
                cout << (ans*tmp).val() << ' ';
                if(prob[g_id[i]] != 0) ans *= prob[g_id[i]];
            }else{
                ans /= pre;
                cout << (ans*tmp).val() << ' ';
                if(prob[g_id[i]] != 0) ans *= prob[g_id[i]];
            }
        }else{
            cout << 0 << ' ';
            if(pre != 0) ans /= pre;
            if(prob[g_id[i]] != 0) ans *= prob[g_id[i]];
        }
        if(pre != 0 && prob[g_id[i]] == 0) not_zero--;
        cnt[g_id[i]]++;

        // if(not_zero < m){
        //     cout << 0 << ' ';
        // }else{
        //     cout << ans.val() << ' ';
        // }
        // rep(j, 0, m){
        //     cout << (prob[j]*mint(2).pow(n)).val() << ' ';
        // }
        // cout << endl;
    }
    cout << endl;





    return 0;
}