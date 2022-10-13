#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc024/tasks/arc024_1

int main(){
    int L, R; cin >> L >> R;
    vector<int> l(41), r(41);
    rep(i, 1, L+1){
        int s; cin >> s;
        l[s]++;
    }
    rep(i, 1, R+1){
        int s; cin >> s;
        r[s]++;
    }
    int ans = 0;
    rep(i, 10, 41){
        ans += min(l[i], r[i]);
    }
    cout << ans << endl;
    return 0;
}