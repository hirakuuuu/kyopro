#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_as

// ビットの部分集合の列挙
// https://atcoder.jp/contests/typical90/tasks/typical90_as

int main(){
    int n, k; cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    vector<vector<ll>> dist(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n) dist[i][j] = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    }

    vector<ll> cost(1<<n);
    rep(i, 0, 1<<n){
        rep(j, 0, n){
            rep(l, 0, n){
                if((1<<j)&i and (1<<l)&i) cost[i] = max(cost[i], dist[j][l]);
            }
        }
    }

    vector<vector<ll>> dp(1<<n, vector<ll>(k+1, 1LL<<60));
    rep(i, 0, k+1) dp[0][i] = 0;
    rep(i, 1, 1<<n){
        rep(j, 1, k+1){
            for(int l = i; l != 0; l = (l-1)&i){
                dp[i][j] = min(dp[i][j], max(dp[i-l][j-1], cost[l]));
            }
        }
    }
    cout << dp[(1<<n)-1][k] << endl;
    return 0;
}