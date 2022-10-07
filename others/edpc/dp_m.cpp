#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_m

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    if(k == 0){
        cout << 1 << endl;
        return 0;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(k+1));

    rep(i, 0, n+1){
        dp[i][0] = 1;
        rep(j, 1, k+1){
            // j-1以下のアメを分け合う方法
            dp[i][j] += dp[i][j-1];
            if(i >= 1){
                // j個のアメを分け合う方法
                if(j-a[i]-1 >= 0) dp[i][j] += dp[i-1][j]-dp[i-1][j-a[i]-1];
                else dp[i][j] += dp[i-1][j];
            }

            dp[i][j] %= MOD;
            if(dp[i][j] < 0) dp[i][j] += MOD;
        }
    }

    ll ans = (dp[n][k]-dp[n][k-1])%MOD;
    if(ans < 0) ans += MOD;

    cout << ans << endl;
    

    return 0;
}