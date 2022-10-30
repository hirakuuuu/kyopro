#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc140/tasks/abc140_b

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 1, n) cin >> c[i];
    int ans = 0;
    rep(i, 0, n){
        ans += b[i];
        if(i > 0 and a[i] == a[i-1]+1) ans += c[a[i-1]];
    }
    cout << ans << endl;
    
    return 0;
}