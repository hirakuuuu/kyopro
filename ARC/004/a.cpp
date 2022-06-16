#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc004/tasks/arc004_1

double x[101], y[101];

int main(){
    int n; cin >> n;
    rep(i, 0, n) cin >> x[i] >> y[i];
    double ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            ans = max(ans, sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
        }
    }
    printf("%.10f\n", ans);
    
    return 0;
}