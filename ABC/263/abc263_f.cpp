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
// https://atcoder.jp/contests/abc263/tasks/abc263_f

int main(){
    int n; cin >> n;
    vector<vector<ll>> c(1<<n, vector<ll>(n+1));
    rep(i, 0, 1<<n){
        rep(j, 1, n+1) cin >> c[i][j];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(1<<n));
    vector<vector<ll>> mx(n+1, vector<ll>(1<<n));
    rep(i, 1, n+1){
        rep(j, 0, 1<<n){
            dp[i][j] = dp[i-1][j]+mx[i-1][(j>>(i-1))^1]+c[j][i]-c[j][i-1];
            chmax(mx[i][j>>i], dp[i][j]);
        }
    }
    ll ans = 0;
    rep(i, 0, 1<<n) chmax(ans, dp[n][i]);
    cout << ans << endl;
    
    return 0;
}