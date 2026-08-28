#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

static ll dp[505][505];
static ll acc[505];
static ll a[505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        acc[i + 1] = acc[i] ^ a[i];
    }

    for (int len = 2; len <= n; ++len) {
        int max_l = n - len;
        if (len & 1) {
            for (int l = 0; l <= max_l; ++l) {
                int r = l + len;
                ll res = 4e18;
                for (int m = l + 1; m < r; ++m) {
                    res = min(res, dp[l][m] + dp[m][r]);
                }
                dp[l][r] = res;
            }
        } else {
            for (int l = 0; l <= max_l; ++l) {
                int r = l + len;
                ll res = 4e18;
                ll cost = (acc[r] ^ acc[l]) << 1;
                
                for (int m = l + 1; m < r; m += 2) {
                    res = min(res, dp[l][m] + dp[m][r] + cost);
                }
                for (int m = l + 2; m < r; m += 2) {
                    res = min(res, dp[l][m] + dp[m][r]);
                }
                dp[l][r] = res;
            }
        }
    }

    ll ans = dp[0][n];
    if (n & 1) ans += acc[n];
    cout << ans << endl;

    return 0;
}