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
// https://atcoder.jp/contests/abc317/tasks/abc317_d

int main(){
    int n; cin >> n;
    vector<ll> x(n+1), y(n+1), z(n+1);
    ll sum_z = 0;
    rep(i, 1, n+1) cin >> x[i] >> y[i] >> z[i];
    rep(i, 1, n+1) sum_z += z[i];

    // vector<vector<ll>> dp(n+1, vector<ll>(10005, INF));
    vector<ll> dp(sum_z+1, INF);
    dp[0] = 0;
    rep(i, 1, n+1){
        vector<ll> dp_ = dp;
        if(x[i] > y[i]){
            rep(j, 0, sum_z+1){
                if(j+z[i] < sum_z+1){
                    chmin(dp[j+z[i]], dp_[j]);
                }
            }
        }else{
            rep(j, 0, sum_z+1){
                if(j+z[i] < sum_z+1){
                    chmin(dp[j+z[i]], dp_[j]+(y[i]-x[i]+1)/2);
                }  
            }
        }
    }

    ll ans = dp[sum_z/2+1];
    rep(i, sum_z/2+1, sum_z+1){
        chmin(ans, dp[i]);
    }
    cout << ans << endl;
    
    return 0;
}