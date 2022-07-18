#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc015/tasks/abc015_4

int dp[51][10005][51];

int main(){
    int w, n, k; cin >> w >> n >> k;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];

    rep(i, 1, n+1){
        rep(j, 0, w+1){
            rep(l, 1, n+1){
                if(j >= a[i-1]){
                    dp[i][j][l] = max(dp[i-1][j][l], dp[i-1][j-a[i-1]][l-1]+b[i-1]);
                }else{
                    dp[i][j][l] = dp[i-1][j][l];
                }
            }
        }
    }

    cout << dp[n][w][k] << endl;
    return 0;
}