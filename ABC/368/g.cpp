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
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    FenwickTree<ll> bit(n);
    rep(i, 0, n) bit.set(i, a[i]);
    set<int> s;
    rep(i, 0, n){
        if(b[i] >= 2) s.insert(i);
    }
    s.insert(n);

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i, x; cin >> i >> x;
            i--;
            a[i] = x;
            bit.set(i, x);
        }else if(t == 2){
            int i, x; cin >> i >> x;
            i--;
            b[i] = x;
            if(b[i] == 1) s.erase(s.find(i));
            if(b[i] >= 2) s.insert(i);
        }else{
            int l, r; cin >> l >> r;
            // [l, r) の中に 2 以上の b の個数は 高々 60 以下
            auto itr = s.lower_bound(l);
            ll ans = 0;
            if(itr == s.end()){
                ans = bit.sum(l-1, r);
            }else{
                ans = bit.sum(l-1, min(r, *itr));
                int tmp = *itr;
                while(tmp < r){
                    // cout << ans << ' ' << tmp << endl;
                    ans = max(ans+a[tmp], ans*b[tmp]);
                    tmp++;
                    itr++;
                    if(itr == s.end()){
                        ans += bit.sum(tmp, r);
                        break;
                    }else{
                        ans += bit.sum(tmp, min(r, *itr));
                        tmp = *itr;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}