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
    vector<pair<ll, ll>> ab(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n){
        ab[i] = {a[i], b[i]};
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    map<ll, vector<ll>> c;
    rep(i, 0, n){
        c[ab[i].first].push_back(ab[i].second);
    }
    FenwickTree<ll> ft(n);
    ll ans = 0;
    for(auto aa: a){
        for(auto bb: c[aa]){
            int pos = lower_bound(b.begin(), b.end(), bb)-b.begin();
            ft.add(pos, 1);
        }
        for(auto bb: c[aa]){
            int pos = lower_bound(b.begin(), b.end(), bb)-b.begin();
            ans += ft.sum(pos, n);
        }
    }
    cout << ans << endl;

    
    return 0;
}