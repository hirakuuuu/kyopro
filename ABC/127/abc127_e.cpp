#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc127/tasks/abc127_e


vector<ll> fac(200005), inv(200005), finv(200005);

void init_fac(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, 200005){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

ll nCr(ll n, ll r){
    if(n < 0 or n-r < 0 or r < 0) return 0;
    return fac[n]*(finv[n-r]*finv[r]%MOD)%MOD;
}

ll nHr(ll n, ll r){
    return nCr(n+r-1, r);
}

int main(){
    init_fac();
    ll n, m, k; cin >> n >> m >> k;
    ll ans = 0;
    ans += ((n*(n-1)*(n+1)/6)%MOD)*((m*m)%MOD)%MOD;
    ans += ((m*(m-1)*(m+1)/6)%MOD)*((n*n)%MOD)%MOD;
    ans %= MOD;
    
    ans *= nCr(n*m-2, k-2);
    ans %= MOD;
    cout << ans << endl;



    
    return 0;
}