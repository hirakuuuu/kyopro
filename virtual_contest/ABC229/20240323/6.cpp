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
// https://atcoder.jp/contests/agc012/tasks/agc012_b

int main(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    vector<vector<ll>> dp(n, vector<ll>(2, INF));
    ll ans = INF;
    // 1と0が同じ集合
    dp[0][0] = a[0];
    rep(i, 1, n){
        dp[i][0] = min(dp[i-1][0]+b[i-1], dp[i-1][1])+a[i];
        dp[i][1] = min(dp[i-1][1]+b[i-1], dp[i-1][0]);
    }
    chmin(ans, min(dp[n-1][0]+b[n-1], dp[n-1][1]));
    // 1と0が違う集合
    rep(i, 0, n) rep(j, 0, 2) dp[i][j] = INF;
    dp[0][1] = 0;
    rep(i, 1, n){
        dp[i][0] = min(dp[i-1][0]+b[i-1], dp[i-1][1])+a[i];
        dp[i][1] = min(dp[i-1][1]+b[i-1], dp[i-1][0]);
    }
    chmin(ans, min(dp[n-1][1]+b[n-1], dp[n-1][0]));
    
    cout << ans << endl;
    
    return 0;
}