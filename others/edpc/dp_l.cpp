#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_l

ll dp[3005][3005][2];

int main(){
    int n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n+1) cin >> a[i];

    rep(i, 1, n+1){
        dp[i][i][0] = a[i];
        dp[i][i][1] = -a[i];
    }

    rep(i, 1, n){
        rep(j, 1, n-i+1){
            int l = j, r = j+i;
            dp[l][r][0] = max(dp[l+1][r][1]+a[l], dp[l][r-1][1]+a[r]);
            dp[l][r][1] = min(dp[l+1][r][0]-a[l], dp[l][r-1][0]-a[r]);
        }
    }

    cout << dp[1][n][0] << endl;
    
    return 0;
}