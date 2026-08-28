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

using S = pair<ll, ll>;
S op(S a, S b) {
    return {(a.first*b.first)%n, a.second+b.second};
}

S e() {
    return {1, 0};
}

// 一次関数 a x + b によって恒等写像と代入を表現
using F = ll;
F id() { return LLONG_MIN; }
S mapping(F a, S x) { 
    if(a == id()) return x;
    return {a*x.second, x.second}; 
}
// a(b(x)) という包含関係
F composition(F a, F b) { 
    if(a == id()) return b;
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        vector<int> cnt(n);
        rep(i, 0, n){
            cin >> a[i];
            a[i] %= n;
            cnt[a[i]]++;
        }
        bool ok = true;
        rep(i, 0, n){
            if(cnt[i] == 0) ok = false;
        }
        if(!ok){
            cout << 0 << endl;
            continue;
        }


        segtree<S, op, e> seg(n);
        ll ans = 1;
        seg.set(a[0], {(n-a[0])%n, 1});
        rep(i, 1, n){
            auto [mul1, _] = seg.prod(0, a[i]);
            auto [mul2, cnt] = seg.prod(a[i]+1, n);
            seg.set(a[i], {(n-a[i])%n, 1});
        }
        if(a.size() < n){
            cout << 0 << endl;
        }else{
            ll ans = 1;
            rep(i, 1, n){
                ans *= power(i, n-i, n);
                ans %= n;
            }
            cout << ans << endl;
        }
    }
    return 0;
}