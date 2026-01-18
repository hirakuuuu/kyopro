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
    auto square_count = [&](ll n) -> ll {
        // n 以下の平方数の個数
        ll sn = sqrt(n);
        if(sn*sn > n) sn--;
        if((sn+1)*(sn+1) <= n) sn++;
        return sn;
    };
    auto range_square_count = [&](ll l, ll r) -> ll {
        if(l > r) return 0;
        return square_count(r)-square_count(l-1);
    };

    int t; cin >> t;
    while(t--){
        ll c, d; cin >> c >> d;
        int len_c = to_string(c).size();
        ll ans = 0;
        for(int k = 0; len_c*2+k <= 19; k++){
            ll b = c;
            rep(_, 0, k+len_c) b *= 10;
            b += c;

            ll xl = 1;
            rep(_, 0, k+len_c-1) xl *= 10;
            xl = max(1LL, xl-c);

            ll xr = 1;
            rep(_, 0, k+len_c) xr *= 10;
            xr = min(d, xr-c-1);
            
            ans += range_square_count(b+xl, b+xr);
            // cout << k << ' ' << ' ' << xl << ' ' << xr << ' ' << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}