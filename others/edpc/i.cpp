#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_i

int main(){
    int n; cin >> n;
    vector<double> p(n+1);
    rep(i, 1, n+1) cin >> p[i];

    vector<double> dp(n+1);
    dp[0] = 1.0;

    rep(i, 1, n+1){
        vector<double> dp_(n+1);
        rep(j, 1, i+1){
            dp_[j] += dp[j-1]*p[i];
        }

        rep(j, 0, i){
            dp_[j] += dp[j]*(1.0-p[i]);
        }

        dp = dp_;
    }

    double ans = 0.0;

    rep(i, n/2+1, n+1){
        ans += dp[i];
    }

    printf("%.10f\n", ans);



    return 0;
}