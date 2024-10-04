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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    // mint::set_mod(m);
    vector<ll> fact(n+1);
    fact[0] = fact[1] = 1;
    rep(i, 2, n+1) fact[i] = (fact[i-1]*i)%m;

    vector<ll> finv(n+1);
    finv[n] = 1;
    rrep(i, n-1, 0) finv[i] = (finv[i+1]*(i+1))%m;

    ll ans = 0, sum = 0, pn = 1;
    rrep(l, n-1, 0){
        sum = (sum*(n-l-1)+pn)%m;
        ans += (((finv[n-1-l]*sum)%m)*l)%m;
        ans %= m;
        pn = (pn*n)%m;
    }

    cout << ans << endl;


    
    return 0;
}