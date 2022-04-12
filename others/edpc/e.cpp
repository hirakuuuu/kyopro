#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/edpc/tasks/dp_e

int main(){
    ll n, W; cin >> n >> W;
    vector<ll> w(n), v(n);
    rep(i, 0, n) cin >> w[i] >> v[i];
    ll sum_v = 0, sum_w = 0;
    vector<vector<ll>> dp(n+1, vector<ll>(100005, (1LL<<60)));
    rep(i, 1, n+1){
        dp[i][0] = 0;
        sum_v += v[i-1];
        sum_w += w[i-1];
        dp[i][sum_v] = sum_w;
        for(ll j = sum_v-1; j > 0; j--){
            if(j >= v[i-1]) dp[i][j] = min(dp[i][j+1], min(dp[i-1][j], dp[i-1][j-v[i-1]]+w[i-1]));
            else dp[i][j] = min(dp[i][j+1], dp[i-1][j]);
        }
    }

    int ans = 0;
    while(dp[n][ans] <= W){
        ans++;
    }
    cout << ans-1 << endl;
    return 0;
}