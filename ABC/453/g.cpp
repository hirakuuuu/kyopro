#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
- おもしろい！！！
- 数列を置き換える→根ノードを共有して同じ状態を持つようにする
- 根からそのノードへの変更クエリをすべて対応した数列を持つように木を作ってあげる
- この木の上でDFSをしてあげるとよい
- 永続セグ木でも解ける
*/

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
    ll n, m, q; cin >> n >> m >> q;

    vector<vector<int>> g(1);
    vector<int> cur(n, 0);
    vector<tuple<ll, ll, ll>> query = {{-2, -2, -2}};
    int nv = 0;
    rep(i, 0, q){
        int t; cin >> t;
        if(t == 1){
            ll x, y; cin >> x >> y; x--, y--;
            cur[x] = cur[y];
        }else if(t == 2){
            ll x, y, z; cin >> x >> y >> z; x--, y--;
            g.push_back({});
            g[cur[x]].push_back(nv+1);
            cur[x] = nv+1;
            query.push_back({-1, y, z});
            nv++;
        }else{
            ll x, l, r; cin >> x >> l >> r; x--, l--;
            g.push_back({});
            g[cur[x]].push_back(nv+1);
            query.push_back({i, l, r});
            nv++;
        }
    }

    vector<ll> ans(q, -1);
    FenwickTree<ll> bit(m);
    auto f = [&](auto self, int pos, int pre) -> void {
        auto [id, y, z] = query[pos];
        // cout << y << ' ' << y+1 << endl;
        ll now = -INF;
        if(id == -1){
            now = bit.sum(y, y+1);
            bit.set(y, z);
        }else if(inr(0, id, q)){
            ans[id] = bit.sum(y, z);
        }
        for(auto nxt: g[pos]){
            self(self, nxt, pos);
        }
        if(id == -1){
            bit.set(y, now);
        }
    };
    
    f(f, 0, -1);
    rep(i, 0, q){
        if(ans[i] == -1) continue;
        cout << ans[i] << endl;
    }
    return 0;
}