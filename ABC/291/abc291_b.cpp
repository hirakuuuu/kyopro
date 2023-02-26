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
// https://atcoder.jp/contests/abc291/tasks/abc291_b

int main(){
    int n; cin >> n;
    vector<double> x(5*n);
    rep(i, 0, 5*n) cin >> x[i];
    sort(x.begin(), x.end());
    double total = 0.0;
    rep(i, n, 4*n){
        total += x[i];
    }
    printf("%.10f\n", (double)total/(3*n));
    return 0;
}