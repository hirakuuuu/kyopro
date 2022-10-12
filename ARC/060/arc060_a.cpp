#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc044/tasks/arc060_a

ll dp[55][55][2505];

int main(){
    int n, a; cin >> n >> a;
    vector<ll> c(n+1);
    rep(i, 1, n+1) cin >> c[i];

    dp[0][0][0] = 1;
    rep(i, 1, n+1){
        rep(j, 0, i+1){
            rep(k, 0, 2505){
                dp[i][j][k] += dp[i-1][j][k];
                if(j >= 1 and k >= c[i]) dp[i][j][k] += dp[i-1][j-1][k-c[i]];
            }
        }
    }

    ll ans = 0;
    rep(i, 1, n+1){
        ans += dp[n][i][a*i];
    }

    cout << ans << endl;

    return 0;
}