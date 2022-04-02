#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc246/tasks/abc246_b

int main(){
    double a, b; cin >> a >> b;
    double d = sqrt(a*a+b*b);
    printf("%.10f %.10f\n", a/d, b/d);
    
    return 0;
}