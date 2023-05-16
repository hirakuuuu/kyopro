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

// 0ならば素数, 0でないなら最小の素因数
vector<int> erat(100005);
void init_e(){
    rep(i, 2, sqrt(100005)){
        if(erat[i] == 0){
            for(int j = i*i; j <= 100005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

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

ll nHr(ll n, ll r){
    return nCr(n+r-1, r);
}


int main(){
    ll n, m; cin >> n >> m;
    init_e();
    init_fac();
    ll ans = 1;
    rep(i, 2, 100005){
        if(erat[i] == 0){
            int cnt = 0;
            while(m%i == 0){
                m /= i;
                cnt++;
            }
            ans *= nHr(n, cnt);
            ans %= mod;
        }
    }

    if(m != 1){
        ans *= n;
        ans %= mod;
    }
    cout << ans << endl;

    
    return 0;
}