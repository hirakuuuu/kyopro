#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cv

double x[20], y[20];

double dist(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main(){
    int n; cin >> n;
    rep(i, 0, n) cin >> x[i] >> y[i];

    double ans = 1000000;
    // sがスタート地点
    rep(s, 0, n){
        vector<vector<double>> dp((1<<n), vector<double>(n, 1000000));
        dp[0][s] = 0;
        // iが現在通っている都市の集合
        rep(i, 0, (1<<n)){
            // jが現在自分がいる位置
            rep(j, 0, n){
                // kがこれから向かおうとしている都市
                rep(k, 0, n){
                    if(j == k) continue;
                    dp[(i|(1<<k))][k] = min(dp[(i|(1<<k))][k], dp[i][j]+dist(j, k));
                }
            }
        }
        ans = min(ans, dp[(1<<n)-1][s]);
    }

    printf("%.10f\n", ans);
    
    return 0;
}