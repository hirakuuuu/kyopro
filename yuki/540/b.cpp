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
    ll k, n; cin >> k >> n;
    
    auto my_sqrt = [&](ll x) -> ll {
        ll ok = 0, ng = 2e9;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            if(mid*mid <= x) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    map<ll, bool> memo;
    ll ans = 0;
    for(ll x = 1; x*x*x*x*x*x <= n; x++){
        ll x6 = x*x*x*x*x*x;
        for(ll y = 1; y*y*y*y <= n-x6; y++){
            ll y4 = y*y*y*y;
            if(memo[x6+y4]) continue;

            ll tmp = x6+y4;
            if(tmp%k == 0){
                ll z2 = tmp/k;
                ll z = my_sqrt(z2);
                if(z*z == z2){
                    memo[x6+y4] = true;
                    ans++;
                }
            }
        }
    }


   
    cout << ans << endl;
    return 0;
}