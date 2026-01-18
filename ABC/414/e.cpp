#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
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

    mint p1 = n;
    p1 *= n;

    mint p2 = n;
    p2 *= (n-1);
    p2 /= 2;

    mint p3 = 0;
    for(ll b = 1; b <= 1000000; b++){
        p3 += n/b;
    }
    ll l, r = max(1000001LL, n+1);
    for(ll nb = 1; nb <= 1000000; nb++){
    // for(ll nb = 1; nb <= 10; nb++){
        l = max(1000001LL, n/(nb+1)+1);
        mint len = r-l;
        // cout << nb << ' ' << l << ' ' << r << endl;
        p3 += len*nb;
        r = l;
    }
    // cout << p2.val() << ' ' << p3.val() << endl;


    mint ans = p1-p2-p3;
    cout << ans.val() << endl;

    return 0;
}