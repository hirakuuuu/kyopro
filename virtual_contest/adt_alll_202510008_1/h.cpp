#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    ll n; cin >> n;
    mint mn = n;
    mint ans = mn*(mn+1)/2;

    // a%b == 0
    rep(b, 1, min(1000001LL, n+1)){
        ll cnt = n/b;
        // cout << b << ' ' << cnt << endl;
        ans -= cnt;
    }
    // cout << ans.val() << endl;
    rep(nb, 1, min(1000001LL, n+1)){
        // n/x == nb となる l <= x < r;
        ll l = max(1000001LL, (nb+nb)/(nb+1));
        ll r = max(1000001LL, n/nb+1);
        ans -= r-l;
    }

    cout << ans.val() << endl;

    
    return 0;
}