#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc256/tasks/abc256_a

int main(){
    ll n; cin >> n;
    ll ans = 1;
    rep(i, 0, n) ans *= 2;
    cout << ans<< endl;
    
    return 0;
}