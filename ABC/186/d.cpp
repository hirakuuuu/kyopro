#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc186/tasks/abc186_d

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    rep(i, 0, n){
        ans += (n-i-1)*(-a[i])+i*a[i];
    }
    cout << ans << endl;

    
    return 0;
}