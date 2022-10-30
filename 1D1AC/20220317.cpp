#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n, k; cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    vector<vector<ll>> dist(n, vector<ll>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            dist[i][j] = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        }
    }

    vector<ll> cost(1<<n);
    rep(i, 0, 1<<n){
        rep(j, 0, n){
            rep(l, 0, j){
                if((i>>j)&1 and (i>>l)&1){
                    cost[i] = max(cost[i], dist[j][l]);
                }
            }
        }
    }

    vector<vector<ll>> dp(k+1, vector<ll>(1<<n, (1LL<<62)));
    dp[0][0] = 0;
    rep(i, 1, k+1){
        rep(j, 1, 1<<n){
            for(int l = j; l != 0; l = (l-1)&j){
                dp[i][j] = min(dp[i][j], max(dp[i-1][j-l], cost[l]));
            }
        }
    }
    cout << dp[k][(1<<n)-1] << endl;
  
}