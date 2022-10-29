#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc275/tasks/abc275_b

int main(){
    ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    a %= mod;
    b %= mod;
    c %= mod;
    d %= mod;
    e %= mod;
    f %= mod;

    ll l = (a*b%mod)*c%mod;
    ll r = (d*e%mod)*f%mod;

    if(l-r < 0) cout << (l-r+mod)%mod << endl;
    else cout << (l-r)%mod << endl;
    
    return 0;
}