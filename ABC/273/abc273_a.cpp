#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc273/tasks/abc273_a

ll f(ll k){
    if(k == 0) return 1;
    return f(k-1)*k;
}

int main(){
    ll n; cin >> n;
    cout << f(n) << endl;

    
    return 0;
}