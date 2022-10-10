#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_de

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(k + 1);
    rep(i, 1, k + 1) cin >> a[i];

    vector<int> dp(n + 1);
    rep(i, 1, n + 1) {
        rep(j, 1, k + 1) {
            if (i >= a[j] and dp[i - a[j]] == 0) dp[i] = 1;
        }
    }

    if (dp[n] == 1) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}