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

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int main(){
    int t; cin >> t;
    while(t--){
        ll a, b, c; cin >> a >> b >> c;
        ll k; cin >> k;
        
        pair<ll, ll> ans = {0, 1};
        auto calc = [&](ll x, ll y, ll z) -> pair<ll, ll> {
            ll ok = IINF, ng = 0;
            while(ok-ng > 1){
                ll mid = (ok+ng)/2;
                if((__int128_t)(y*mid/x)*(z*mid/x) >= (__int128_t)(k+mid-1)/mid) ok = mid;
                else ng = mid;
            }
            ll g = gcd(x, ok);
            return {x/g, ok/g};
        };

        auto q1 = calc(a, b, c);
        auto q2 = calc(b, a, c);
        auto q3 = calc(c, a, b);
        if(ans.first*q1.second < ans.second*q1.first) ans = q1;
        if(ans.first*q2.second < ans.second*q2.first) ans = q2;
        if(ans.first*q3.second < ans.second*q3.first) ans = q3;
        cout << ans.first << ' ' << ans.second << endl;
    }

    return 0;
}