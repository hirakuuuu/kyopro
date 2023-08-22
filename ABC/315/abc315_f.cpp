#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc315/tasks/abc315_f

vector<double> x(10005), y(10005);
double dist(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main(){
    int n; cin >> n;
    rep(i, 0, n) cin >> x[i] >> y[i];

    vector<vector<double>> dp(n, vector<double>(31, 9e18));
    dp[0][0] = 0.0;
    rep(i, 0, n){
        rep(j, 1, 32){
            rep(k, 0, 31){
                if(i+j < n && j+k-1 <= 30) chmin(dp[i+j][k+j-1], dp[i][k]+dist(i, i+j));
            }
        }
    }


    double ans = dp[n-1][0];
    rep(i, 1, 31){
        chmin(ans, dp[n-1][i]+pow(2, i-1));
    }
    printf("%.10f\n", ans);
    
    return 0;
}