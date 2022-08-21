#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc265/tasks/abc265_a

int main(){
    int x, y, n; cin >> x >> y >> n;

    cout << min(x*n, y*(n/3)+x*(n%3)) << endl;
    
    return 0;
}