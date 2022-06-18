#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc256/tasks/abc256_b

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n+1);
    rep(i, 0, n) cin >> a[i];
    reverse(a.begin(), a.end());
    rep(i, 0, n){
        b[i+1] = a[i]+b[i];
        cout << b[i+1] << endl;
    }

    int ans = b.end()-lower_bound(b.begin(), b.end(), 4);
    cout << ans << endl;

    
    return 0;
}