#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_ax

int main(){
    int n, l; cin >> n >> l;
    vector<int> dp(n+1);
    dp[0] = 1;
    rep(i, 0, n){
        if(i+1 <= n){
            dp[i+1] += dp[i];
            dp[i+1] %= MOD;
        }
        if(i+l <= n){
            dp[i+l] += dp[i];
            dp[i+l] %= MOD;
        }
    }
    cout << dp[n] << endl;
    
    return 0;
}