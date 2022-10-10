#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ai

int main() {
    int n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n + 1) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    rep(i, 1, n + 1) dp[n][i] = a[i];

    for (int i = n - 1; i > 0; i--) {
        if (i % 2 == 1) {
            rep(j, 1, i + 1) {
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        else {
            rep(j, 1, i + 1) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
    }

    cout << dp[1][1] << endl;

    return 0;
}