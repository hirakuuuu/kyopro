#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc216/tasks/abc216_f

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<vector<int>> ab;
    rep(i, 0, n){
        ab.push_back({a[i], b[i]});
    }

    sort(ab.begin(), ab.end());

    vector<vector<ll>> dp(n+1, vector<ll>(5005, 0));
    rep(i, 0, 5005) dp[0][i] = 1;
    rep(i, 1, n+1){
        dp[i][0] = 1;
        rep(j, 1, 5005){
            if(j >= ab[i-1][1]) dp[i][j] = (dp[i-1][j-ab[i-1][1]]+dp[i-1][j])%mod;
            else dp[i][j] = dp[i-1][j];
        }
    }

    ll ans = 0;
    rep(i, 0, n){
        if(ab[i][0] < ab[i][1]) continue;
        ans += dp[i][ab[i][0]-ab[i][1]];
        ans %= mod;
    }
    cout << ans << endl;

    return 0;
}