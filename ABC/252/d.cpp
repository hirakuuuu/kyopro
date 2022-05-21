#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc252/tasks/abc252_d

int main(){
    ll n; cin >> n;
    vector<ll> a(200005);
    rep(i, 0, n){
        ll A; cin >> A;
        a[A]++;
    }
    ll ans = n*(n-1)*(n-2)/6;

    rep(i, 0, 200005){
        if(a[i] >= 3) ans -= a[i]*(a[i]-1)*(a[i]-2)/6;
        if(a[i] >= 2) ans -= (a[i]*(a[i]-1)/2)*(n-a[i]);
    }
    cout << ans << endl;

    
    return 0;
}