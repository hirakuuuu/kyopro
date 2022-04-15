#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc145/tasks/abc145_e

int main(){
    ll n, t; cin >> n >> t;
    vector<ll> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i] >> b[i];
    vector<vector<pll>> dp(3001, vector<pll>(3001));
    
    rep(i, 1, n+1){
        rep(j, 0, t){
            if(j < a[i]){
                dp[i][j] = {dp[i-1][j].first, max(dp[i-1][j].second, b[i])};
            }else{
                ll sum1 = dp[i-1][j].first+max(dp[i-1][j].second, b[i]);
                ll sum2 = dp[i-1][j-a[i]].first+b[i] + dp[i-1][j-a[i]].second;
                if(sum1 > sum2){
                    dp[i][j] = {dp[i-1][j].first, max(dp[i-1][j].second, b[i])};
                }else if(sum1 < sum2){
                    dp[i][j] = {dp[i-1][j-a[i]].first+b[i], dp[i-1][j-a[i]].second};
                }else{
                    if(dp[i-1][j].first >= dp[i-1][j-a[i]].first+b[i]){
                        dp[i][j] = {dp[i-1][j].first, max(dp[i-1][j].second, b[i])};
                    }else{
                        dp[i][j] = {dp[i-1][j-a[i]].first+b[i], dp[i-1][j-a[i]].second};
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(i, 0, t){
        ans = max(dp[n][i].first+dp[n][i].second, ans);
    }
    cout << ans << endl;    
    return 0;
}