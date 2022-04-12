#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc150/tasks/abc150_d

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

ll n2(ll a){
    ll res = 0, b = a;
    while(b%2 == 0){
        b /= 2;
        res++;
    }
    return res;
}

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i] /= 2;
    }

    ll cnt = n2(a[0]);
    rep(i, 1, n){
        if(cnt != n2(a[i])){
            cout << 0 << endl;
            return 0;
        }
    }


    ll lcm = 1;
    rep(i, 0, n){
        lcm = lcm*a[i]/gcd(lcm, a[i]);
        if(lcm > m){
            cout << 0 << endl;
            return 0;
        }
    }


    ll ans = m/lcm;
    cout << ans/2+ans%2 << endl;    
    return 0;
}