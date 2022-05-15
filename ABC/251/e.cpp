#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc251/tasks/abc251_e

int main(){
    int n; cin >> n;
    vector<ll> a(n+1);
    rep(i, 0, n) cin >> a[i];
    vector<vector<ll>> dp_1(2, vector<ll>(n)), dp_2(2, vector<ll>(n));
    dp_1[0][0] = 0, dp_1[1][0] = 1LL<<60; 
    rep(i, 1, n){
        dp_1[0][i] = dp_1[1][(i-1)%n];
        dp_1[1][i] = min(dp_1[0][(i-1)%n], dp_1[1][(i-1)%n])+a[i];
    }

    dp_2[0][0] = 1LL<<60, dp_2[1][0] = a[0]; 
    rep(i, 1, n){
        dp_2[0][i] = dp_2[1][(i-1)%n];
        dp_2[1][i] = min(dp_2[0][(i-1)%n], dp_2[1][(i-1)%n])+a[i];
    }

    cout << min(dp_1[1][n-1], min(dp_2[0][n-1], dp_2[1][n-1])) << endl;
    return 0;
}