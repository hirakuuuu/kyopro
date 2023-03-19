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
// https://atcoder.jp/contests/arc049/tasks/arc049_b

int main(){
    int n; cin >> n; 
    vector<double> x(n), y(n), c(n);
    rep(i, 0, n) cin >> x[i] >> y[i] >> c[i];

    double ans = 0.0;

    rep(i, 0, n){
        rep(j, i+1, n){
            double dist = max(abs(x[i]-x[j]), abs(y[i]-y[j]));
            chmax(ans, c[i]*c[j]*dist/(c[i]+c[j]));
        }
    }

    printf("%.10f\n", ans);
    return 0;
}