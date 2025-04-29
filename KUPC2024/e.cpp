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
    vector<ll> a(9), b(9);
    rep(i, 0, 9) cin >> a[i];
    rep(i, 0, 9) cin >> b[i];

    ll ans = 0;
    rep(i, 0, 9) rep(j, 0, 9) ans += a[i]*b[j];
    cout << ans << endl;
    
    return 0;
}