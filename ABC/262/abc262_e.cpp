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
// https://atcoder.jp/contests/abc262/tasks/abc262_e

vector<ll> fac(200005), inv(200005), finv(200005);

void init_fac(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, 200005){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = mod-mod/i*inv[mod%i]%mod;
        finv[i] = finv[i-1]*inv[i]%mod;
    }
}

ll nCr(ll n, ll r){
    if(n < 0 or n-r < 0 or r < 0) return 0;
    return fac[n]*(finv[n-r]*finv[r]%mod)%mod;
}

int main(){
    init_fac();
    int n, m, k; cin >> n >> m >> k;
    vector<int> dim(n+1);
    rep(i, 0, m){
        int u, v; cin >> u >> v;
        dim[u]++;
        dim[v]++;
    }

    int cnt_o = 0;
    rep(i, 1, n+1){
        cnt_o += (dim[i]%2 == 1);
    }

    ll ans = 0;
    rep(i, 0, k+1){
        if(i%2 == 0 and cnt_o >= i and n-cnt_o >= k-i){
            ans += nCr(cnt_o, i)*nCr(n-cnt_o, k-i);
            ans %= mod;
        }
    }

    cout << ans << endl;

    
    return 0;
}