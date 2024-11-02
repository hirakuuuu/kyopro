#include <bits/stdc++.h>
//多倍長整数//
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using lll = mp::cpp_int;

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
constexpr int IINF = 1005005005;

/*
拡張ユークリッドで求まる一般解について, 係数は最大公約数で割った値になる（だいぶぬまった）
*/


template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll extGCD(ll a, ll b, ll &x, ll &y){
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

// 1 <= at+b <= n を満たす t の範囲
pair<ll, ll> calc_range(ll a, ll b, ll n){
    ll l, r;
    if(a >= 0){
        if(1-b >= 0) l = (1-b+(a-1))/a;
        else l = (1-b)/a;
        if(n-b >= 0) r = (n-b)/a;
        else r = (n-b-(a-1))/a;
    }else{
        // -n <= -at-b <= -1 を満たす t の範囲を求める
        a = -a, b = -b;
        if(-n-b >= 0) l = (-n-b+(a-1))/a;
        else l = (-n-b)/a;
        if(-1-b >= 0) r = (-1-b)/a;
        else r = (-1-b-(a-1))/a; 
    }
    return {l, r};
}

int main(){
    ll n, a, b, c, x; cin >> n >> a >> b >> c >> x;
    ll g_bc = gcd(b, c);
    b /= g_bc, c /= g_bc;

    ll cj, ck;
    extGCD(b, c, cj, ck);
    
    ll ans = 0;
    for(ll i = 1; i <= n && x-a*i > 0; i++){
        ll d = x-a*i;
        if(d%g_bc != 0) continue;


        ll j = cj*(d/g_bc), k = ck*(d/g_bc);
        // b' = b/gcd(b, c), c' = c/gcd(b, c) として
        // j = c'*t+cj, k = -b'*t+ck (t: 整数)
        // それぞれ 1 から n の範囲に入る t を求めたい
        auto [l1, r1] = calc_range(c, j, n);
        auto [l2, r2] = calc_range(-b, k, n);
        if(l1 <= r1 && l2 <= r2) ans += max((ll)0, min(r1, r2)-max(l1, l2)+1);
    }
    cout << ans << endl;
    return 0;
}