#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
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
    int n, k; cin >> n >> k;
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i], p[i]--;
    
    // k 個の順列のシャッフルによる転倒数の期待値
    mint inv_k = 0;
    rep(i, 1, k+1){
        mint tmp = mint(i)*(i-1)/2;
        inv_k += tmp/i;
    }
    // cout << inv_k.val() << endl;

    // そもそものk個の区間における転倒数
    vector<ll> cur_inv_count(n-k+1);
    {
        FenwickTree<ll> bit(n);
        vector<int> aft_k(n); // 自分よりｋ個まで後ろでの転倒数
        rrep(i, n-1, 0){
            aft_k[i] = bit.sum(0, p[i]);
            bit.add(p[i], 1);
            if(i <= n-k) bit.add(p[i+k-1], -1);
            // cout << i << ' ' << aft_k[i] << endl;
        }
        rep(i, 0, n) bit.set(i, 0);

        rep(i, 0, k){
            cur_inv_count[0] += bit.sum(p[i], n);
            bit.add(p[i], 1);
        }
        rep(i, k, n){
            cur_inv_count[i-k+1] = cur_inv_count[i-k];
            cur_inv_count[i-k+1] -= aft_k[i-k];
            bit.add(p[i-k], -1);
            cur_inv_count[i-k+1] += bit.sum(p[i], n);
            bit.add(p[i], 1);
        }
    }

    FenwickTree<ll> bit(n);
    vector<ll> inv_count(n);
    rep(i, 0, n){
        inv_count[i] = bit.sum(p[i], n);
        bit.add(p[i], 1);
    }

    FenwickTree<ll> bit2(n);
    rep(i, 0, n){
        bit2.add(i, inv_count[i]);
    }

    // cout << bit2.sum(0, n) << endl;
    mint ans = 0;
    rep(i, 0, n-k+1){
        mint tmp = inv_k;
        // cout << cur_inv_count[i] << endl;
        tmp += bit2.sum(0, n)-cur_inv_count[i];
        ans += tmp;
    }
    ans /= n-k+1;
    cout << ans.val() << endl;
    return 0;
}