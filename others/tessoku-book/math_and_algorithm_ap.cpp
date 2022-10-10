#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/math_and_algorithm_ap

int main(){
    int n; cin >> n;
    vector<ll> a(n+1);
    a[1] = a[2] = 1;

    rep(i, 3, n+1){
        a[i] = (a[i-1]+a[i-2])%MOD;
    }

    cout << a[n] << endl;
    
    return 0;
}