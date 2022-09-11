#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc266/tasks/abc266_e

int main(){
    int n; cin >> n;
    vector<double> f(n+1);
    f[1] = 3.5;
    rep(i, 2, n+1){
        if(f[i-1] > 5){
            f[i] = (double)6/6+(double)f[i-1]*5/6;
        }else if(f[i-1] > 4){
            f[i] = (double)(5+6)/2/3+(double)f[i-1]*2/3;
        }else{
            f[i] = (double)(4+5+6)/3/2+(double)f[i-1]/2;
        }
    }

    printf("%.10f\n", f[n]);

    
    return 0;
}