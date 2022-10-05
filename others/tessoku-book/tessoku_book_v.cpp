#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_v

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<vector<pii>> from_score(n+1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];

    vector<int> dp(n+1, -(1<<30));
    dp[1] = 0;

    rep(i, 1, n){
        dp[a[i]] = max(dp[a[i]], dp[i]+100);
        dp[b[i]] = max(dp[b[i]], dp[i]+150);

    }

    cout << dp[n] << endl;

    return 0;
}