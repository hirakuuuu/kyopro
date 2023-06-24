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


int main(){
    int n; cin >> n;
    vector<ll> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) cin >> b[i];

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(2, INF)));
    dp[1][0][0] = a[1];
    dp[1][1][1] = 0;
    rep(i, 2, n+1){
        dp[i][0][0] = min(dp[i-1][0][0]+b[i-1], dp[i-1][0][1])+a[i];
        dp[i][0][1] = min(dp[i-1][0][0], dp[i-1][0][1]+b[i-1]);

        dp[i][1][0] = min(dp[i-1][1][0]+b[i-1], dp[i-1][1][1])+a[i];
        dp[i][1][1] = min(dp[i-1][1][0], dp[i-1][1][1]+b[i-1]);
        
    }
    ll ans = min(min(dp[n][0][0]+b[n], dp[n][0][1]), min(dp[n][1][0], dp[n][1][1]+b[n]));
    cout << ans << endl;

    return 0;
}