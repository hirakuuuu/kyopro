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


void comp(vector<int>&a){
  set<int>s(a.begin(),a.end());
  map<int,int>d;
  int cnt=0;
  for(auto x:s)d[x]=cnt++;
  for(auto&x:a)x=d[x];
}


int main(){
    int n; cin >> n;
    vector<tuple<int, int, int>> lr(n);
    vector<int> r_(n), sr(n);
    rep(i, 0, n){
        int l, r; cin >> l >> r;
        lr[i] = {l, r, i};
        r_[i] = r;
        sr[i] = r;
    }
    comp(r_);
    sort(lr.begin(), lr.end());
    sort(sr.begin(), sr.end());
    sr.erase(unique(sr.begin(), sr.end()), sr.end());

    FenwickTree<ll> ft(n);
    ll ans = 0;
    rep(i, 0, n){
        auto [l, r, ind] = lr[i];
        int tmp = lower_bound(sr.begin(), sr.end(), l)-sr.begin();
        ans += ft.sum(tmp, n);
        ft.add(r_[ind], 1);
    }
    cout << ans << endl;

    
    return 0;
}