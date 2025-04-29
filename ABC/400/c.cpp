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
    auto sqrt = [](ll x)->ll{ // sqrtの誤差がないバージョン
        ll l = 0, r = (ll)3e9+100;
        while(r-l > 1){
            ll mid = (l+r)/2;
            if(mid*mid <= x) l = mid;
            else r = mid;
        }
        return l;
    };
    ll ans = 0;
    rep(a, 1, 61){
        if(n < 1LL<<a){
            break;
        }
        ll thl = n/(1LL<<a);
        ans += (sqrt(thl)+1)/2;
    }
    cout << ans << endl;
    
    return 0;
}