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

/*
n 個の整数の集合の部分集合の xor として考えられる値は 2^n 個
でもこれは重複があって、高々 2^60 個くらいになるよね
だったら 60 個くらいの数列で表現できた方がうれしい
そういうときのための xor 基底
*/

// reference: https://miscalc.hatenablog.com/entry/2024/03/21/235130
vector<ll> xor_basis(vector<ll> a){
    // msb (ビットが立っている最大の桁) がほかの数字では０になるような基底にする
    vector<ll> basis;
    for(int i = 0; i < (int) a.size(); i++){
        for (auto b : basis){
            if ((a[i] ^ b) < a[i]) a[i] ^= b;
        }
        for (auto &&b : basis){
            if ((a[i] ^ b) < b) b ^= a[i];
        }
        if(a[i]) basis.emplace_back(a[i]);
    }
    sort(basis.begin(), basis.end());
    return basis;
}

// verify: https://atcoder.jp/contests/abc283/tasks/abc283_g
int main(){
    int n;
    ll l, r; cin >> n >> l >> r;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> basis = xor_basis(a);

    for(ll i = l-1; i < r; i++){
        ll ans = 0;
        rep(j, 0, basis.size()){
            if((i>>j)&1) ans ^= basis[j];
        }
        cout << ans << ' ';
    }



    return 0;
}