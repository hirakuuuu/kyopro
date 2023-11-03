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
// 

int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, -INF));
    rep(i, 0, n+1) dp[i][0] = 0;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            dp[i][j] = dp[i-1][j];
            if(dp[i-1][j-1] != -INF) chmax(dp[i][j], dp[i-1][j-1]+j*a[i-1]);
        }
    }

    cout << dp[n][m] << endl;
    
    return 0;
}