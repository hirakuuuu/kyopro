#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ck

double f(double x){
    return x*x*x+x;
}

int main(){
    double n; cin >> n;

    double l = 0.0, r = 100.0, m = (l+r)/2;
    while(fabs(f(m)-n) >= 0.0001){
        if(f(m) < n) l = m;
        else r = m;
        m = (l+r)/2;
    }

    printf("%.10f\n", m);
    
    return 0;
}