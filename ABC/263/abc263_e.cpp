#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc263/tasks/abc263_e

// dp[i] = (マスiからマスnに到達するまでに振る回数の期待値)

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
    int n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n) cin >> a[i];

    vector<ll> dp(n+2);
    vector<ll> dp_(n+2);
    dp[n] = 0;
    dp_[n] = 0;
    for(int i = n-1; i > 0; i--){
        dp[i] = ((dp_[i+1]-dp_[i+a[i]+1]+mod)*power(a[i], mod-2)%mod+power(a[i], mod-2)+1)%mod;
        dp_[i] = dp_[i+1]+dp[i];
        dp_[i] %= mod;
    }

    cout << dp[1] << endl;
    
    return 0;
}