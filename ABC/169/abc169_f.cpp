#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc169/tasks/abc169_f


ll modpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b&1){
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ll n, s; cin >> n >> s;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(s+1));
    dp[0][0] = 1;
    rep(i, 0, n){
        rep(j, 0, s+1){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
            if(j+a[i] <= s){
                dp[i+1][j+a[i]] += dp[i][j]*modpow(2, MOD-2);
            }
        }
    }

    ll ans = dp[n][s]*modpow(2, n);
    ans %= MOD;
    cout << ans << endl;
    
    return 0;
}