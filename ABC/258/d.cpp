#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc258/tasks/abc258_d

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n+1), b(n+1);
    rep(i, 1, n+1){
        cin >> a[i] >> b[i];
    }

    vector<ll> dp(n+1);
    rep(i, 1, n+1){
        dp[i] = dp[i-1]+a[i]+b[i];
    }
    ll ans = (1LL<<60);
    rep(i, 1, n+1){
        dp[i] += b[i]*max(x-i, 0LL);
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;


    
    return 0;
}