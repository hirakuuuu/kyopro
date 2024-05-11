#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll ans = n; // (i, 1) は条件を満たす
        rep(b, 2LL, m+1){
            // (i, b) が条件を満たすかどうか
            ll M = b*b;
            ll l = 2*b+(M-2*b%M)%M;
            ll r = (n+b)-(n+b)%M;
            // cout << l << ' ' << r << endl;
            ans += max(0LL, (r-l)/M+1);
            // cout << b << ' ' << ans << endl;
        }
        cout << ans << endl;

    }
    return 0;
}