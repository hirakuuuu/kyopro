#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc275/tasks/abc275_d



ll f(ll n, map<ll, ll> &m){
    if(n == 0) return 1;
    if(m[n]) return m[n];
    m[n/2] = f(n/2, m);
    m[n/3] = f(n/3, m);
    return m[n/2]+m[n/3];
}

int main(){
    ll n; cin >> n;
    map<ll, ll> m;

    cout << f(n, m) << endl;

    
    return 0;
}