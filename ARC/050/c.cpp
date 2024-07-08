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

ll power(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    ll x, y, m; cin >> x >> y >> m;
    ll g = gcd(x, y);
    // f(x)*f(y)/f(g) を m で割ったあまり
    // ⇒ f(x)*h(y, g) を m で割ったあまり h(y, g) := f(y)/f(g) 

    vector<ll> amari(60);
    amari[0] = 1;
    rep(i, 1, 60){
        amari[i] = (amari[i-1]*power(10, (1LL<<i-1), m))%m + amari[i-1];
        amari[i] %= m;
    }

    auto f = [&](ll x) -> ll {
        ll res = 0;
        rep(i, 0, 60){
            if((x>>i)&1){
                res = (res*power(10, (1LL<<i), m))%m + amari[i];
                res %= m;
            }
        }
        return res;
    };

    vector<ll> amari2(60);
    amari2[0] = 1;
    rep(i, 1, 60){
        amari2[i] = (amari2[i-1]*power(10, g*(1LL<<i-1), m))%m + amari2[i-1];
        amari2[i] %= m;
    }

    auto h = [&](ll y) -> ll {
        ll res = 0;
        rep(i, 0, 60){
            if((y>>i)&1){
                res = (res*power(10, g*(1LL<<i), m))%m + amari2[i];
                res %= m;
            }
        }
        return res;

    };
    cout << (f(x)*h(y/g))%m << endl;

    return 0;
}