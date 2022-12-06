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
// https://atcoder.jp/contests/abc280/tasks/abc280_e

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
    ll n, p; cin >> n >> p;
    ll p1 = (100-p)*power(100, mod-2)%mod;
    ll p2 = p*power(100, mod-2)%mod;
    vector<ll> dp(n+1);
    dp[1] = 1;
    rep(i, 2, n+1){
        dp[i] = ((dp[i-1]+1)*p1%mod+(dp[i-2]+1)*p2%mod)%mod;
    }

    cout << dp[n] << endl;
    
    return 0;
}