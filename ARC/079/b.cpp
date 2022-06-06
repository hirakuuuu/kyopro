#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc068/tasks/arc079_b

int main(){
    ll k; cin >> k;
    ll n = 50;
    cout << n << endl;
    ll m = k%n;
    rep(i, 0, m){
        cout << n+k/n << " ";
    }
    rep(i, 0, n-m){
        cout << (n-m-1)+k/n << " ";
    }
    cout << endl;
    
    return 0;
}