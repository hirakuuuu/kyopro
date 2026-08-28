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
constexpr ll INF = 2e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


// 遅延セグメント木の準備
using S = mint;
S op(S a, S b) { return a+b; }
S e() { return 0; }
// 一次関数 a x + b によって恒等写像と代入を表現
using F = pair<mint, mint>;
S mapping(F a, S x) {
    return a.first*x+a.second; 
}
// a(b(x)) という包含関係
F composition(F a, F b) { return {a.first*b.first, a.first*b.second+a.second}; }
F id() { return {1, 0}; }

int main(){

    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    rep(i, 0, n){
        seg.set(i, a[i]);
    }

    rep(i, 0, m){
        int l, r; cin >> l >> r; l--;
        int x; cin >> x;
        seg.apply(l, r, {mint(1)-mint(r-l).inv(), mint(r-l).inv()*x});
    }
    rep(i, 0, n){
        cout << seg.get(i).val() << ' ';
    }
    cout << endl;



    return 0;
}