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
// https://atcoder.jp/contests/abc285/tasks/abc285_e

int main(){
    ll n; cin >> n;
    vector<ll> a(5005);
    rep(i, 1, n+1) cin >> a[i];

    vector<ll> score(5005);
    for(int i = 1; i <= 5000; i+= 2){
        score[i] += score[i-1]+a[i/2+1];
        score[i+1] += score[i]+a[i/2+1];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
    dp[1][0] = 0;
    rep(i, 1, n){
        rep(j, 0, n+1){
            if(dp[i][j] < 0) continue;
            chmax(dp[i+1][j+1], dp[i][j]);
            chmax(dp[i+1][0], dp[i][j]+score[j]);
        }
    }
    ll ans = 0;
    rep(i, 0, n){
        chmax(ans, dp[n][i]+score[i]);
    }
    cout << ans << endl;
    
    return 0;
}