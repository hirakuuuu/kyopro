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

int main(){
    int t; cin >> t;
    auto f = [&](auto self, ll a, ll b, ll c, ll d) -> pair<ll, ll> {
        ll n = a/b;
        a -= n*b;
        c -= n*d;

        if(c > d){
            return {1LL+n, 1LL};
        }

        auto [q, p] = self(self, d, c, b, a);
        return {p+n*q, q};
    };

    while(t--){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        auto [p, q] = f(f, a, b, c, d);
        cout << q << endl;
    }
    
    return 0;
}