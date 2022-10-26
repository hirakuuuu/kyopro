#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const ll MOD = 1000000007;
const ll mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc228/tasks/abc228_e

ll bimpower(ll a, ll b, ll m){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    ll n, k, m; cin >> n >> k >> m;
    if(m%mod == 0){
        cout << 0 << endl;
        return 0;
    }
    k %= mod-1;
    m %= mod;
    ll a = bimpower(k, n, mod-1);
    cout << bimpower(m, a, mod) << endl;
    
    return 0;
}