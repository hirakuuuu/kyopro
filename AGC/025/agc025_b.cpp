#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/agc025/tasks/agc025_b

vector<ll> fac(300005), inv(300005), finv(300005);

void init_fac(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, 300005){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = mod-mod/i*inv[mod%i]%mod;
        finv[i] = finv[i-1]*inv[i]%mod;
    }
}

ll nCr(ll n, ll r){
    if(n < 0 or n-r < 0 or r < 0) return 0;
    return fac[n]*(finv[n-r]*finv[r]%mod)%mod;
}

ll nHr(ll n, ll r){
    return nCr(n-r+1, r);
}

int main(){
    init_fac();
    ll n, a, b, k; cin >> n >> a >> b >> k;
    ll ans = 0;
    rep(i, 0, n+1){
        if(k-a*i >= 0 and (k-a*i)%b == 0 and (k-a*i)/b <= n){
            ll j = (k-a*i)/b;
            ans += nCr(n, i)*nCr(n, j);
            ans %= mod;
        }
    }

    cout << ans << endl;
    
    return 0;
}