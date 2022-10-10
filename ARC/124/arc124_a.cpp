#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc124/tasks/arc124_a

int main() {
    int n, k; cin >> n >> k;

    vector<int> sum(n + 1), conf(n + 1);
    rep(i, 1, k + 1) {
        char c; cin >> c;
        int x; cin >> x;
        conf[x] = i;
        if (c == 'L') {
            sum[x]++;
        }
        else {
            sum[1]++;
            sum[x]--;
        }
    }

    rep(i, 1, n + 1) {
        sum[i] += sum[i - 1];
    }

    ll ans = 1;

    rep(i, 1, n + 1) {
        if (conf[i] == 0) ans *= sum[i];
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}