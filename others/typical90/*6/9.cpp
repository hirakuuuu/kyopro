#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_i

const double PI = 3.14159265358979;

int main(){
    int n; cin >> n;
    vector<double> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    vector<vector<double>> arg_vec(n);

    // 中心をiとしたときの偏角を度数法で計算しソート
    rep(i, 0, n){
        rep(j, 0, n){
            if(i == j) continue;
            double ARG = atan2(y[j]-y[i], x[j]-x[i])*180/PI;
            if(ARG < 0) ARG += 360;
            arg_vec[i].push_back(ARG);
        }
        sort(arg_vec[i].begin(), arg_vec[i].end());
    }
    
    // 中心をi, 1つの角をjとしたときの最大角を求める
    double ans = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            if(i == j) continue;
            double arg_ij = atan2(y[j]-y[i], x[j]-x[i])*180/PI;
            if(arg_ij < 0) arg_ij += 360;
            arg_ij += 180;
            if(arg_ij >= 360) arg_ij -= 360;

            int pos = lower_bound(arg_vec[i].begin(), arg_vec[i].end(), arg_ij)-arg_vec[i].begin();
            double g1 = arg_vec[i][pos%(n-1)];
            double g2 = arg_vec[i][(pos+n)%(n-1)];
            g1 = min(abs(arg_ij-g1), 360-abs(arg_ij-g1));
            g2 = min(abs(arg_ij-g2), 360-abs(arg_ij-g2));
            ans = max(ans, 180-min(g1, g2));
        }
    }

    printf("%.10f\n", ans);

    return 0;
}