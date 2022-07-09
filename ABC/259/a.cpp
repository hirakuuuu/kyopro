#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc259/tasks/abc259_a

int main(){
    int n, m, x, t, d; cin >> n >> m >> x >> t >> d;
    int origin = t-d*min(x, n);
    cout << origin+d*min(x, m) << endl;
    
    return 0;
}