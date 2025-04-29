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
    ll n; cin >> n;
    ll cbrt_n = 0;
    while(cbrt_n*cbrt_n*cbrt_n <= n) cbrt_n++;
    cbrt_n--;

    auto my_sqrt = [&](ll x) -> ll {
        ll ok = 0, ng = 2e9;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            if(mid*mid <= x) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    for(ll d = 1; d <= cbrt_n; d++){
        // x-y = d;
        ll d3 = d*d*d;
        if(n-d3 <= 0) continue;
        if((n-d3)%(3*d) != 0) continue;
        ll m = (n-d3)/(3*d);
        
        ll l = d*d+4*m;
        ll tmp = my_sqrt(l);
        if(tmp*tmp != l) continue;
        if((tmp-d)%2 == 1) continue;
        ll y = (tmp-d)/2;
        // cout << y << endl;
        ll x = y+d;
        cout << x << ' ' << y << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}