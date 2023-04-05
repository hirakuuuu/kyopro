#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc292/tasks/abc292_f

int main(){
    double a, b; cin >> a >> b;
    if(a > b) swap(a, b);

    if(sqrt(3)*b >= 2.0*a){
        printf("%.10f\n", 2.0*a/sqrt(3));
    }else{
        printf("%.10f\n", b/(cos(atan(2.0*a/b-sqrt(3)))));
    }
    
    return 0;
}