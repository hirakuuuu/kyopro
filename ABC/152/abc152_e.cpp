#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const ll MOD = 1000000007;
const ll mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc152/tasks/abc152_e

// 0ならば素数, 0でないなら最小の素因数
vector<ll> erat(1000005);
void init_e(){
    rep(i, 2, 1000005){
        if(erat[i] == 0){
            erat[i] = i;
            for(ll j = (ll)i*i; j < 1000005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

ll power(ll a, ll b, ll m=mod){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    init_e();
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> cnt(1000005);
    rep(i, 0, n){
        ll b = a[i];
        while(erat[b] != 0){
            ll c = 0, d = erat[b];
            while(b%d == 0){
                b /= d; 
                c++;
            }
            chmax(cnt[d], c);
        }
    }

    ll k = 1;
    rep(i, 2, 1000005){
        k *= power(i, cnt[i], MOD);
        k %= MOD;
    }

    ll ans = 0;
    rep(i, 0, n){
        ans += (k*power(a[i], MOD-2, MOD))%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}