#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc129/tasks/abc129_c

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    rep(i, 0, m){
        int A; cin >> A;
        a[A] = 1;
    }
    vector<int> dp(n+1);
    dp[0] = 1;
    if(a[1]) dp[1] = 0;
    else dp[1] = 1;
    rep(i, 2, n+1){
        if(a[i]) continue;
        dp[i] = (dp[i-1]+dp[i-2])%MOD;
    }
    cout << dp[n] << endl;
    
    return 0;
}