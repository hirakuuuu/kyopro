#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
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

/*
二分探索
中央値が mid 以上になる部分列がｋ個以上存在するかを判定
これは a を mid以上なら１、そうでないならー１とした配列を考え、区間和が０以上となる区間を数え上げれればよい
これは累積和をとった配列の転倒数に帰着されるので、Fenwick Tree 等を用いる

*/

int main(){
    ll n; cin >> n;
    ll k = (n*(n+1)/2+1)/2;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ok = 0, ng = IINF;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        vector<int> b(n);
        rep(i, 0, n){
            if(a[i] < mid) b[i] = 1;
        }
        int acc = 0;
        FenwickTree<ll> ft(3*n+5);
        ft.add(n, 1);
        ll tmp = 0LL;
        rep(i, 1, n+1){
            acc += b[i-1];
            tmp += ft.sum(2*acc-i+n, 3*n+5);
            ft.add(2*acc-i+n, 1);
        }

        if(tmp >= k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}