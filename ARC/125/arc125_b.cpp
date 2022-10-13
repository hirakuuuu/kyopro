#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc125/tasks/arc125_b

/*
 x^2 - y = z^2とすると, (x+z)(x-z) = yである.
 p = x+z, q = x-z とすると, x = (p+q)/2, y = pqである.
 1 <= q <= sqrt(n)であるから, qを全探索して, 
 q <= p <= n/qかつp+q = 0(mod2)を満たすpを数え上げれば良い.
*/
int main(){
    ll n; cin >> n;
    ll ans = 0;
    rep(q, 1, sqrt(n)+1){
        ans += (n/q-q+1+1)/2;
        ans %= mod;
    }
    cout << ans << endl;


    
    return 0;
}