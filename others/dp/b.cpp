#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_b

int main(){
    int n, k; cin >> n >> k;
    vector<int> h(n+1);
    rep(i, 1, n+1) cin >> h[i];
    vector<int> dp(n+1, 1000000007);
    rep(i, 2, min(n+1, k+2)){
        dp[i] = abs(h[i]-h[1]);
    }
    rep(i, k+2, n+1){
        rep(j, i-k, i){
            dp[i] = min(dp[i], dp[j]+abs(h[i]-h[j]));
        }
    }
    cout << dp[n] << endl;
    
    return 0;
}