#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc148/tasks/arc148_a

int main(){
    ll n; cin >> n;
    vector<ll> a(n), gap(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 1, n){
        gap[i] = abs(a[i]-a[0]);
    }

    ll mg = 0;
    rep(i, 1, n){
        mg = gcd(mg, gap[i]);
    }

    if(mg != 1){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
    }
    return 0;
}