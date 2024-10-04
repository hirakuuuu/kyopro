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
    ll n, s; cin >> n >> s;

    auto f = [&](auto self, ll b, ll n) -> ll {
        if(n < b) return n;
        return self(self, b, n/b)+n%b;
    };
    
    ll ans = INF;
    // 1桁の場合
    if(n == s) ans = n+1;

    // 3桁以上になる場合
    for(ll b = 2; b < 1000005; b++){
        if(f(f, b, n) == s) chmin(ans, b);
    }

    // 2桁になる場合 → 2桁目を全探索
    vector<ll> r(1000005, INF);
    for(ll b2 = 1; b2 < 1000005; b2++){
        r[b2] = n/b2;
    }
    for(ll b2 = 1; b2 < 1000000; b2++){
        // r[b2+1] < a <= r[b2]
        ll m = s-b2;
        if(m < 0) continue;
        ll ok = r[b2], ng = r[b2+1];
        if(b2 >= ok) continue;
        // cout << b2 << ' ' << ok << ' ' << ng << endl;
        while(ok-ng > 1){
            ll mid = (ok+ng)/2;
            if(n%mid <= m) ok = mid;
            else ng = mid;
        }
        if(n/ok+n%ok == s) chmin(ans, ok);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    
    return 0;
}