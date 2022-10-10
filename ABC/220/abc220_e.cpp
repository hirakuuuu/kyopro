#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc220/tasks/abc220_e

ll bimpower(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res *= a;
        res %= m;
        a *= a;
        a %= m;
        b /= 2;
    }
    return res;
}

int main(){
    ll n, d; cin >> n >> d;
    ll ans = 0;
    for(int i = n; i > 0; i--){
        if(i > d){
            ans += (d+3)*bimpower(2, n-i+d-1, mod);
            ans %= mod;
        }else{
            ans += max(0LL, d-1-2*(d-i))*bimpower(2, n-i+d-1, mod);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}