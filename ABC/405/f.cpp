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
    vector<vector<int>> even(2*n+1);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        even[a].push_back(b);
    }
    int q; cin >> q;
    vector<vector<pair<int, int>>> odd(2*n+1);
    rep(i, 0, q){
        int c, d; cin >> c >> d;
        odd[c].push_back({d, i});
    }
    vector<int> ans(q);

    FenwickTree<ll> bit(2*n+1);
    FenwickTree<ll> bit2(2*n+1);
    rep(l, 2, 2*n+1){
        if(l%2 == 1) continue;
        for(auto r: even[l]){
            bit.add(r, 1);
            bit2.add(l, 1);
            bit2.add(r, 1);
        }
    }
    rep(l, 1, 2*n+1){
        if(l%2 == 1){
            for(auto [r, i]: odd[l]){
                ans[i] = bit2.sum(l, r)-2*bit.sum(0, r);
            }
        }else{
            for(auto r: even[l]){
                bit.add(r, -1);
            }
        }
    }


    rep(i, 0, q){
        cout << ans[i] << endl;
    }


    
    return 0;
}