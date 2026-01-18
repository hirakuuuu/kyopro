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
    int q; cin >> q;
    FenwickTree<ll> bit(5000005);
    rep(i, 1, 5000005) bit.add(i, 1);

    vector<bool> del(5000005);
    while(q--){
        int a, b; cin >> a >> b;
        // cout << a << ' ' << b << endl;

        // a の倍数を削除
        if(a < 5000005){
            bool f = true;
            for(ll j = 1; j*j <= a; j++){
                if(a%j == 0){
                    if(del[j]) f = false;
                    if((a/j) != j){
                        if(del[a/j]) f = false;
                    }
                }
            }
            if(f){
                for(ll j = a; j < 5000005; j += a){
                    bit.set(j, 0);
                }
            }
            del[a] = true;
        }
        // cout << b << endl;

        ll ng = 0, ok = 5000005;
        while(ok-ng > 1){
            ll mid = (ok+ng)/2;
            if(b <= bit.sum(0, mid)) ok = mid;
            else ng = mid;
        }
        cout << ng << endl;
    }

    return 0;
}