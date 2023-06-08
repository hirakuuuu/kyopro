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
// https://atcoder.jp/contests/yahoo-procon2019-qual/tasks/yahoo_procon2019_qual_d

int main(){
    ll l; cin >> l;
    vector<ll> a(l+1);
    rep(i, 1, l+1) cin >> a[i];

    vector<vector<ll>> dp(l+1, vector<ll>(5));
    rep(i, 1, l+1){
        vector<ll> min_dp(5);
        min_dp[0] = dp[i-1][0];
        rep(j, 1, 5) min_dp[j] = min(min_dp[j-1], dp[i-1][j]);

        // 1つ目の0の区間とする
        dp[i][0] = min_dp[0]+a[i];
        // 1つ目の偶数の区間とする
        if(a[i] == 0) dp[i][1] = min_dp[1]+2;
        else dp[i][1] = min_dp[1]+a[i]%2;
        // 奇数の区間とする
        dp[i][2] = min_dp[2]+(1-a[i]%2);
        // 2つ目の偶数の区間とする
        if(a[i] == 0) dp[i][3] = min_dp[3]+2;
        else dp[i][3] = min_dp[3]+a[i]%2;
        // 2つ目の0の区間とする
        dp[i][4] = min_dp[4]+a[i];
    }

    ll ans = (1LL<<60);
    rep(i, 0, 5) chmin(ans, dp[l][i]);
    cout << ans << endl;


    
    return 0;
}