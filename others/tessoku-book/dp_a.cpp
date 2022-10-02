#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/dp_a

int main(){
    int n; cin >> n;
    vector<int> h(n+1);
    rep(i, 1, n+1) cin >> h[i];
    vector<int> dp(n+1, 1000000007);
    dp[1] = 0;
    dp[2] = abs(h[1]-h[2]);

    rep(i, 3, n+1){
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
    }

    cout << dp[n] << endl;
    
    return 0;
}