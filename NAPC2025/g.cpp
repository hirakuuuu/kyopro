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
    auto f = [&](ll a, ll b) -> ll {
        ll res = (a+1)*b;
        ll ab = a*b;
        rep(_, 0, to_string(res).size()) ab *= 10;
        res += ab;
        return res;
    };
    ll ans = 0;
    for(ll a = 1; a < 100001; a++){
        ll ok = 0, ng = (IINF+a-1)/a;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            if(f(a, mid) <= n) ok = mid;
            else ng = mid;
        }
        ans += ok;
    }
    cout << ans << endl;
    
    return 0;
}