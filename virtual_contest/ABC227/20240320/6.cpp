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
// 

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<vector<ll>> a(h+1, vector<ll>(w+1));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> a[i][j];
        }
    }
    ll ans = INF;
    for(auto y: a) for(auto x: y){
        vector<vector<vector<ll>>> dp(k+1, vector<vector<ll>>(h, vector<ll>(w, INF)));
        if(a[0][0] >= x) dp[1][0][0] = a[0][0];
        if(a[0][0] <= x) dp[0][0][0] = 0;
        rep(i, 0, k+1){
            rep(j, 0, h){
                rep(l, 0, w){
                    if(j < h-1){
                        if(i < k && a[j+1][l] >= x) chmin(dp[i+1][j+1][l], dp[i][j][l]+a[j+1][l]);
                        if(a[j+1][l] <= x) chmin(dp[i][j+1][l], dp[i][j][l]);
                    }
                    if(l < w-1){
                        if(i < k && a[j][l+1] >= x) chmin(dp[i+1][j][l+1], dp[i][j][l]+a[j][l+1]);
                        if(a[j][l+1] <= x) chmin(dp[i][j][l+1], dp[i][j][l]);
                    }
                }
            }
        }
        chmin(ans, dp[k][h-1][w-1]);
    }
    cout << ans << endl;
    return 0;
}