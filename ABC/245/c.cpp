#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc245/tasks/abc245_c

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1), b(n+1);
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) cin >> b[i];
    vector<vector<int>> dp(2, vector<int>(n+1));
    dp[0][1] = dp[1][1] = 1;
    rep(i, 1, n){
        if(dp[0][i]){
            if(abs(a[i+1]-a[i]) <= k) dp[0][i+1] = 1;
            if(abs(b[i+1]-a[i]) <= k) dp[1][i+1] = 1;
        }
        if(dp[1][i]){
            if(abs(a[i+1]-b[i]) <= k) dp[0][i+1] = 1;
            if(abs(b[i+1]-b[i]) <= k) dp[1][i+1] = 1;
        }
    }
    if(dp[0][n] or dp[1][n]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}