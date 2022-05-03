#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc017/tasks/abc017_3

int main(){
    int n, m; cin >> n >> m;
    vector<int> l(n), r(n), s(n), ruiseki(m+2);
    ll sum = 0;
    rep(i, 0, n){
        cin >> l[i] >> r[i] >> s[i];
        sum += s[i];
        ruiseki[l[i]] += s[i];
        ruiseki[r[i]+1] -= s[i];
    }
    rep(i, 1, m+1) ruiseki[i+1] += ruiseki[i];
    ll ans = 0;
    rep(i, 1, m+1){
        ans = max(ans, sum-ruiseki[i]);
    }
    cout << ans << endl;
    return 0;
}