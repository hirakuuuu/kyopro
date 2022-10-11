#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc234/tasks/abc234_f

vector<ll> cnt(27), fac(5005), inv(5005), finv(5005);

void init_fac(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    rep(i, 2, 5005){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = mod-mod/i*inv[mod%i]%mod;
        finv[i] = finv[i-1]*inv[i]%mod;
    }
}

ll nCr(ll n, ll r){
    if(n < 0 or n-r < 0 or r < 0) return 0;
    return fac[n]*(finv[n-r]*finv[r]%mod)%mod;
}

vector<vector<ll>> dp(27, vector<ll>(5005));

int main(){
    string s; cin >> s;
    int n = s.size();
    for(auto ss: s){
        cnt[ss-'a']++;
    }
    init_fac();
    ll ans = 0;
    dp[0][0] = 1;

    rep(i, 0, 26){
        rep(j, 0, n+1){
            rep(k, 0, min((ll)j, cnt[i])+1){
                dp[i+1][j] += dp[i][j-k]*nCr(j, k);
                dp[i+1][j] %= mod;
            }
        }
    }

    rep(i, 1, n+1){
        ans += dp[26][i];
        ans %= mod;
    }
    cout << ans << endl;

    
    return 0;
}