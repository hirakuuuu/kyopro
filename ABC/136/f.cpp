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
    int n; cin >> n;
    vector<int> x(n), y(n);
    vector<pair<int, int>> p(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        p[i] = {x[i], y[i]};
    }

    // 座標圧縮
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    {
        map<int, int> xid;
        rep(i, 0, n) xid[x[i]] = i;
        map<int, int> yid;
        rep(i, 0, n) yid[y[i]] = i;
        rep(i, 0, n){
            auto [px, py] = p[i];
            p[i] = {xid[px], yid[py]};
        }
    }

    // 2^i を先に計算しておく
    vector<mint> two(n+1, 1);
    rep(i, 1, n+1) two[i] = two[i-1]*2;


    // y 座標に関するBITを x 座標で 左側と右側で管理する
    FenwickTree<int> l(n), r(n);
    sort(p.begin(), p.end());
    rep(i, 0, n) r.add(p[i].second, 1);

    mint ans = mint(2).pow(n-1)*n; // 自分自身を含む集合による寄与
    rep(i, 0, n){
        // i を含まない集合による、i の寄与
        r.add(p[i].second, -1);

        mint tmp = (two[l.sum(0, n)]-1)*(two[r.sum(0, n)]-1);
        tmp -= (two[l.sum(p[i].second+1, n)]-1)*(two[r.sum(p[i].second+1, n)]-1);
        tmp -= (two[l.sum(0, p[i].second)]-1)*(two[r.sum(0, p[i].second)]-1);
        ans += tmp;

        l.add(p[i].second, 1);
    }
    cout << ans.val() << endl;






    return 0;
}