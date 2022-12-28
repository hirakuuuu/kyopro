#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_c

int main(){
    double n, m, d; cin >> n >> m >> d;
    double ans = 0.0;
    if(d == 0) ans = (m-1)*(n-d)/(n*n);
    else ans = (m-1)*(n-d)*2.0/(n*n);

    printf("%.10f\n", ans);

    
    return 0;
}