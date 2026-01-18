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


int main(){
    ll a, b; cin >> a >> b;
    if(gcd(a, b) >= 3){
        cout << -1 << endl;
        return 0;
    }

    ll x, y;
    extGCD(b, -a, x, y);
    if(gcd(a, b) == 1) x *= 2, y *= 2;
    cout << x << ' ' << y << endl;

    return 0;
}