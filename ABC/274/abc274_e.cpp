#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc274/tasks/abc274_e
vector<ll> x(20), y(20), p(20), q(20);
vector<ll> ac(32);

double dist(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main(){
    ll n, m; cin >> n >> m;
    rep(i, 0, n+m) cin >> x[i] >> y[i];

    rep(i, 0, 32){
        int j = i;
        while(j > 0){
            ac[i] += j%2;
            j /= 2;
        }
    }

    double ans = pow(10, 18);

    rep(i, 0, (1<<m)){
        vector<int> bit;
        rep(j, 0, n) bit.push_back(j);
        rep(j, 0, m) if((i&(1<<j)) > 0) bit.push_back(n+j);
        vector<vector<double>> dp((1<<(n+ac[i])), vector<double>(n+ac[i], pow(10, 18)));
        rep(j, 0, n+ac[i]){
            dp[(1<<j)][j] = sqrt(x[bit[j]]*x[bit[j]]+y[bit[j]]*y[bit[j]]);
        }
        
        rep(j, 1, (1<<(n+ac[i]))){
            rep(k, 0, n+ac[i]){
                if((j&(1<<k)) > 0){
                    rep(l, 0, n+ac[i]){
                        if(l != k and (j&(1<<l)) > 0){
                            dp[j][k] = min(dp[j][k], dp[j-(1<<k)][l]+dist(bit[k], bit[l])/pow(2, ac[((j-(1<<k))>>n)]));
                        }
                    }
                }
            }
        }
        double cost = pow(10, 18);
        rep(j, 0, n+ac[i]) cost = min(cost, dp[(1<<(n+ac[i]))-1][j]+sqrt(x[bit[j]]*x[bit[j]]+y[bit[j]]*y[bit[j]])/pow(2, ac[i]));
        ans = min(ans, cost);
    }
    printf("%.10f\n", ans);    
    return 0;
}