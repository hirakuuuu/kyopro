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


vector<ll> fac(1000005), inv(1000005), finv(1000005);

void init_fac(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, 1000005){
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
    ll x, y; cin >> x >> y;
    rep(i, 0, 2){
        if(2*x-y < 0 || (2*x-y)%3 != 0){
            cout << 0 << endl;
            return 0;
        }
        swap(x, y);
    }

    init_fac();
    ll n = (2*y-x)/3, m = (2*x-y)/3;
    cout << nCr(n+m, n) << endl;




    return 0;
}