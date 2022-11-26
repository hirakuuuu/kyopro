#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc279/tasks/abc279_d

double f(ll k, ll a, ll b){
    return (double)b*k+(double)a/sqrt(1+k);
}

int main(){
    ll a, b; cin >> a >> b;
    double A = a, B = b;
    ll k = ceil(cbrt(A/(2.0*B))*cbrt(A/(2.0*B)));

    if(f(k-1, a, b) < f(k, a, b)){
        printf("%.10f\n", f(k-1, a, b));
    }else{
        printf("%.10f\n", f(k, a, b));
    }
    
    
    return 0;
}