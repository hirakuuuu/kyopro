#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc259/tasks/abc259_b

const double pi = 3.1415926535;
int main(){
    double a, b, d; cin >> a >> b >> d;
    double x = a*cos(d/180*pi)-b*sin(d/180*pi);
    double y = a*sin(d/180*pi)+b*cos(d/180*pi);

    printf("%.10f %.10f\n", x, y);
    
    return 0;
}