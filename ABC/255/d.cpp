#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc255/tasks/abc255_d

int main(){
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> b(n+1);
    rep(i, 1, n+1){
        b[i] += b[i-1]+a[i-1];
    }

    while(q--){
        ll x; cin >> x;
        ll sum = 0;
        int pos = lower_bound(a.begin(), a.end(), x)-a.begin();
        if(pos == 0){
            cout << b[n]-x*n << endl;
        }else if(pos == n){
            cout << x*n-b[n] << endl;
        }else{
            cout << (x*(pos)-b[pos]) + (b[n]-b[pos]-x*(n-pos)) << endl;
        }
    }
    
    return 0;
}