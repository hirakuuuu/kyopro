#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc265/tasks/abc265_e

ll dp[305][305][305];

int main(){
    ll n, m; cin >> n >> m;
    ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    vector<ll> x(m), y(m);
    map<pll, bool> obs;
    rep(i, 0, m){
        cin >> x[i] >> y[i];
        obs[make_pair(x[i], y[i])] = true;
    }

    dp[0][0][0] = 1;

    rep(i, 0, n+1){
        rep(j, 0, n+1){
            if(i+j > n) break;
            rep(k, 0, n+1){
                if(i+j+k > n) break;
                if(!obs[make_pair(a*i+c*j+e*k, b*i+d*j+f*k)]){
                    if(i > 0) dp[i][j][k] += dp[i-1][j][k];
                    if(j > 0) dp[i][j][k] += dp[i][j-1][k];
                    if(k > 0) dp[i][j][k] += dp[i][j][k-1];
                    dp[i][j][k] %= mod;
                }
            }
        }
    }
    
    ll ans = 0;

    rep(i, 0, n+1){
        rep(j, 0, n+1){
            if(i+j > n) break;
            rep(k, 0, n+1){
                if(i+j+k > n) break;
                if(i+j+k == n){
                    ans += dp[i][j][k];
                    ans %= mod;
                }
            }
        }
    }

    cout << ans << endl;


    
    return 0;
}