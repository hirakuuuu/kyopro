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
// https://atcoder.jp/contests/abc332/tasks/abc332_e

int main(){
    int n, d; cin >> n >> d;
    vector<double> w(n);
    double mean = 0.0;
    rep(i, 0, n){
        cin >> w[i];
        mean += w[i];
    }
    mean /= (double)d;

    vector<double> sum(1<<n);
    rep(i, 1, 1<<n){
        rep(j, 0, n){
            if((i>>j)&1){
                sum[i] = sum[i-(1<<j)]+w[j];
                break;
            }
        }
    }

    vector<vector<double>> dp(d+1, vector<double>(1<<n, 9e18));
    rep(i, 0, 1<<n){
        dp[1][i] = (sum[i]-mean)*(sum[i]-mean);
    }
    rep(i, 2, d+1){
        rep(j, 0, 1<<n){
            chmin(dp[i][j], dp[i-1][j]+mean*mean);
            for(int l = j; l != 0; l = (l-1)&j){
                chmin(dp[i][j], dp[i-1][l]+(sum[j^l]-mean)*(sum[j^l]-mean));
            }   
        }
    }

    printf("%.20f\n", (double)dp[d][(1<<n)-1]/d);

    
    return 0;
}