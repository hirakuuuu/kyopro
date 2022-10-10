#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ah

int main() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];

    vector<int> grandy(100005);
    rep(i, 0, 100005) {
        vector<int> g(3);
        if (i >= x) g[grandy[i - x]] = 1;
        if (i >= y) g[grandy[i - y]] = 1;

        rep(j, 0, 3) {
            if (g[j] == 0) {
                grandy[i] = j;
                break;
            }
        }
    }

    int ans = 0;
    rep(i, 1, n + 1) ans ^= grandy[a[i]];

    if (ans > 0) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}