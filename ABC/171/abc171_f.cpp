#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int mod = 1000000007;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc171/tasks/abc171_f

// 繰り返し二乗法
ll power(ll a, ll b, ll m=mod){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

vector<ll> fac(2000005), inv(2000005), finv(2000005);

void init_fac(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, 2000005){
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
    return nCr(n+r-1, r);
}

int main(){
    int k; cin >> k;
    string s; cin >> s;
    int n = s.size();

    init_fac();

    ll ans = 0;
    rep(i, 0, k+1){
        ans += ((nHr(n, k-i)*power(25, k-i))%mod)*power(26, i)%mod;
      	ans %= mod;
    }
    cout << ans << endl;

    return 0;
}