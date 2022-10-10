#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc124/tasks/arc124_b

int main() {
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> ans, b_;
    rep(i, 0, n) {
        b_ = b;
        ll x = a[0] ^ b[i];
        bool f = true;
        rep(j, 0, n) {
            int need = x ^ a[j];
            auto itr = lower_bound(b_.begin(), b_.end(), need);
            int pos = itr - b_.begin();
            if (pos < b_.size() and b_[pos] == need) {
                b_.erase(itr);
            }
            else {
                f = false;
                break;
            }
        }
        if (f) ans.push_back(x);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    for (auto aa : ans) {
        cout << aa << endl;
    }



    return 0;
}