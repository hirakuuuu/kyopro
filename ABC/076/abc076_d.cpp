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
// https://atcoder.jp/contests/abc076/tasks/abc076_d

int main(){
    ll n; cin >> n;
    vector<ll> t(n), v(n);
    rep(i, 0, n) cin >> t[i];
    rep(i, 0, n) cin >> v[i];

    ll total = 0;
    rep(i, 0, n) total += t[i];

    vector<vector<double>> dp(total+1, vector<double>(105, -1.0));
    dp[0][0] = 0.0;
    ll tmp_time = 1;
    rep(i, 0, n){
        rep(j, 0, t[i]){
            rep(k, 0, v[i]+1){
                if(dp[tmp_time-1][k] != -1.0){
                    if(k == v[i]) dp[tmp_time][k] = dp[tmp_time-1][k]+(double)k;
                    else dp[tmp_time][k] = dp[tmp_time-1][k]+(double)k+0.25;
                }
                if(k-1 >= 0 && dp[tmp_time-1][k-1] != -1.0) chmax(dp[tmp_time][k], dp[tmp_time-1][k-1]+(double)(2.0*k-1.0)/2.0);
                if(k+1 <= v[i] && dp[tmp_time-1][k+1] != -1.0) chmax(dp[tmp_time][k], dp[tmp_time-1][k+1]+(double)(2.0*k+1.0)/2.0);
            }
            tmp_time++;
        }
    }


    printf("%.10f\n", dp[total][0]);
    
    return 0;
}