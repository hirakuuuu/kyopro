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
// https://atcoder.jp/contests/abc327/tasks/abc327_e

int main(){
    int n; cin >> n;
    vector<double> p(n);
    rep(i, 0, n) cin >> p[i];

    double l = -1e8, r = 1e8;
    vector<double> sq(n+1);
    rep(i, 1, n+1) sq[i] = sqrt(i);
    while(r-l > 1e-8){
        double x = (r+l)/2;
        vector<double> dp(n+1, -INF);
        dp[0] = 0.0;
        rep(i, 1, n+1){
            vector<double> dp_ = dp;
            rep(j, 1, i+1){
                dp[j] = max(dp_[j], dp_[j-1]*0.9+(p[i-1]-x));
            }
        }

        bool f = false;
        double sum = 1.0;
        rep(i, 1, n+1){
            if(sq[i]*dp[i] >= sum*1200.0) f = true;
            sum = 0.9*sum+1.0;
        }

        if(f) l = x;
        else r = x;
    }
    printf("%.10f\n", l);



    
    return 0;
}