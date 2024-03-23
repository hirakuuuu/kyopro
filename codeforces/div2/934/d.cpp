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

using S = int;
S op(S a, S b) {
    return a+b;
}

S e() {
    return 0;
}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

ll modinv(ll n, ll m=MOD){
    return power(n, m-2, m);
}


int main(){
    int t; cin >> t;
    vector<ll> mod = {998244353, 1000000007, 1000000009};
    int m = (int)mod.size();
    vector<vector<ll>> m10(m, vector<ll>(200005, 1)), minv(m, vector<ll>(200005, 1));
    rep(i, 0, m){
        rep(j, 1, 200005){
            m10[i][j] = (m10[i][j-1]*10)%mod[i];
            minv[i][j] = modinv(m10[i][j], mod[i]);
        }
    }
    while(t--){
        int n, q; cin >> n >> q;
        string s; cin >> s;
        vector<vector<int>> cnt(n+1, vector<int>(26));
        rep(i, 0, n){
            rep(j, 0, 26){
                cnt[i+1][j] = cnt[i][j];
                if(s[i]-'a' == j) cnt[i+1][j]++;
            }
        }
        vector<vector<ll>> hash(m, vector<ll>(n+1)), rev(m, vector<ll>(n+1));
        rep(i, 0, m){
            rep(j, 0, n){
                hash[i][j+1] = (hash[i][j]+m10[i][j]*(s[j]-'a'+1))%mod[i];
                rev[i][j+1] = (rev[i][j]+m10[i][j]*(s[n-j-1]-'a'+1))%mod[i];
            }
        }
        vector<ll> acc(n+1);
        rep(i, 0, n-1) acc[i+1] = acc[i]+(s[i] != s[i+1]);

        while(q--){
            ll l, r; cin >> l >> r;
            l--;
            int kind = 0;
            vector<int> tmp(26);
            rep(i, 0, 26){
                tmp[i] = cnt[r][i]-cnt[l][i];
                if(tmp[i]) kind++;
            }
            if(kind == 1){
                cout << 0 << endl;
            }else if(kind == 2 && acc[r-1]-acc[l] == r-l-1){
                if((r-l)%2 == 0) cout << (ll)((r-l)/2)*((r-l)/2+1) << endl;
                else cout << (ll)((r-l-1)/2)*((r-l-1)/2+1) << endl;
            }else{
                bool ok = true;
                rep(i, 0, m){
                    ll h = ((hash[i][r]-hash[i][l]+mod[i])%mod[i])*minv[i][l]%mod[i];
                    ll h_rev = ((rev[i][n-l]-rev[i][n-r]+mod[i])%mod[i])*minv[i][n-r]%mod[i];
                    if(h != h_rev) ok = false;
                }
                if(ok) cout << (ll)(r-l+2)*(r-l-1)/2-(r-l) << endl;
                else cout << (ll)(r-l+2)*(r-l-1)/2 << endl;
            }
        }
    }
 
    return 0;
}