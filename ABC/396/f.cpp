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

template <class T>
class FenwickTree {

private:
    int _n;
    vector<T> data;

    T sum(int r) {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
    
public:
    FenwickTree() : _n(0) {}
    explicit FenwickTree(int n) : _n(n), data(n) {}

    void set(int p, T x) {
        assert(0 <= p && p < _n);
        T tmp = sum(p+1)-sum(p);
        add(p, x-tmp);
    }

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while(p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    // [l, r)
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

};

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    FenwickTree<ll> cntl(m+1), cntr(m+1), bit(m+1);
    rep(i, 0, n){
        cntr.add(a[i], 1);
    }
    rep(i, 0, n){
        cntr.add(a[i], -1);
        {
            ll cnt_l = cntl.sum(0, a[i]);
            ll cnt_r = cntr.sum(0, a[i]);
            // cout << m-a[i] << ' ' << cnt_l << ' ' << cnt_r << endl;
            bit.add(m-a[i], cnt_l);
            bit.add(0, cnt_r);
            bit.add(m-a[i], -cnt_r);

        }
        {
            ll cnt_l = cntl.sum(a[i]+1, m+1);
            ll cnt_r = cntr.sum(a[i]+1, m+1);
            // cout << m-a[i] << ' ' << cnt_l << ' ' << cnt_r << endl;

            bit.add(m-a[i], cnt_l);
            bit.add(m-a[i], -cnt_r);
        }
        cntl.add(a[i], 1);
    }

    rep(k, 0, m){
        cout << bit.sum(0, k+1) << endl;
    }


    
    return 0;
}