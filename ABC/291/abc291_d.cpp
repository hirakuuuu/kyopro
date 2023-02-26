#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc291/tasks/abc291_d

int main(){
    ll n; cin >> n;
    vector<ll> a(n+1), b(n+1);
    rep(i, 1, n+1){
        cin >> a[i] >> b[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(2));
    dp[1][0] = dp[1][1] = 1;
    rep(i, 2, n+1){
        if(a[i] != a[i-1]) dp[i][0] += dp[i-1][0];
        if(a[i] != b[i-1]) dp[i][0] += dp[i-1][1];
        if(b[i] != a[i-1]) dp[i][1] += dp[i-1][0];
        if(b[i] != b[i-1]) dp[i][1] += dp[i-1][1];
        dp[i][0] %= mod_num;
        dp[i][1] %= mod_num;
    }
    cout << (dp[n][0]+dp[n][1])%mod_num << endl;


    
    return 0;
}