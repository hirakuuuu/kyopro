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

const ll mod = 1000003;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


/*
d = 1 であれば, 1000003 の倍数の有無と, 階乗の前計算で O(1) で計算可能. 
d = 0 の場合を例外として, d >= 1 のときは, 全体を d で割って, d = 1 に帰着した上で d^n を掛ければ良い.
*/

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

int main(){
    init_fac();

    int q; cin >> q;
    while(q--){
        ll x, d, n; cin >> x >> d >> n;
        if(d == 0){
            cout << power(x, n) << endl;
        }else{
            x = (x*inv[d])%mod;
            if(n >= mod || x > (x+n-1)%mod){
                cout << 0 << endl;
            }else{
                cout << (power(d, n)*fac[x+n-1]*finv[x-1])%mod << endl;
            }
        }
    }
    
    return 0;
}