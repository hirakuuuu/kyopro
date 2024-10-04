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

    ll n; cin >> n;
    vector<ll> p(n);
    rep(i, 0, n){ cin >> p[i]; p[i]--; }

    ll m; cin >> m;
    vector<ll> a(m);
    rep(i, 0, m){ cin >> a[i]; a[i]--; }

    // 転倒数を求める
    vector<ll> inv(n);
    FenwickTree<ll> bit(n);
    rep(i, 0, n){
        inv[i] = bit.sum(p[i], n);
        bit.add(p[i], 1);
    }

    // 始めて操作に寄与する位置を求める
    vector<ll> l(n);
    rep(i, 0, n){
        int pos = lower_bound(a.begin(), a.end(), i)-a.begin();
        l[i] = pos;
    }

    vector<ll> acc(m+1);
    rep(i, 0, n){
        acc[l[i]]--;
        acc[min(m, l[i]+inv[i])]++;
    }
    rep(i, 0, m){
        acc[i+1] += acc[i];
    }

    ll tot = 0;
    rep(i, 0, n) tot += inv[i];
    rep(i, 0, m){
        cout << tot+acc[i] << endl;
        tot += acc[i];
    }

    
    return 0;
}