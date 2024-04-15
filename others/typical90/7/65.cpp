#include <bits/stdc++.h>
#include <atcoder/convolution>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

vector<ll> fac(600005), inv(600005), finv(600005);
void initfact(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, 600005){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
ll nCr(ll n, ll r){
    if(n < 0 or n-r < 0 or r < 0) return 0;
    return fac[n]*(finv[n-r]*finv[r]%MOD)%MOD;
}


int main(){
    int r, g, b, k; cin >> r >> g >> b >> k;
    int x, y, z; cin >> x >> y >> z;
    initfact();
    vector<ll> R(r+1), G(g+1);
    rep(i, k-y, r+1) R[i] = nCr(r, i);
    rep(i, k-z, g+1) G[i] = nCr(g, i);
    vector<ll> RG = atcoder::convolution<MOD>(R, G);
    ll ans = 0;
    rep(i, 2*k-y-z, x+1){
        if(k-i > b) continue;
        ans += (RG[i]*nCr(b, k-i))%MOD;
        ans %= MOD;
    }
    cout << ans << endl;


    
    return 0;
}