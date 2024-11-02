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
    rep(i, 0, n){
        cin >> a[i];
        a[i] %= m;
    }

    FenwickTree<ll> bit(m), val(m);
    bit.add(0, 1);
    val.add(0, 0);
    ll acc = 0, ans = 0;
    rep(i, 0, n){
        acc += a[i];
        acc %= m;
        bit.add(acc, 1);
        val.add(acc, acc);

        ans += acc*(bit.sum(0, acc+1))-val.sum(0, acc+1);
        ans += (m+acc)*(bit.sum(acc+1, m))-val.sum(acc+1, m);
    }
    cout << ans << endl;
    return 0;
}