#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc266/tasks/abc266_d

int main(){
    ll n; cin >> n;
    vector<ll> t(n), x(n), a(n);
    rep(i, 0, n) cin >> t[i] >> x[i] >> a[i];

    vector<vector<ll>> dp(100005, vector<ll>(5));

    int pos = 0;
    rep(i, 1, 100005){
        rep(j, 0, 5){
            dp[i][j] = dp[i-1][j];
        }
        if(pos < n and i == t[pos]){
            rep(j, 0, 5){
                rep(k, 0, 5){
                    if(i-(k+abs(j-k)) < 0) continue;
                    if(j == x[pos]){
                        dp[i][j] = max(dp[i][j], dp[i-max(1, abs(j-k))][k]+a[pos]);
                    }else{
                        dp[i][j] = max(dp[i][j], dp[i-max(1, abs(j-k))][k]);
                    }
                }                  
            }
            pos++;
        }
    }

    ll ans = 0;
    rep(i, 0, 5){
        ans = max(ans, dp[100001][i]);
    }
    cout << ans << endl;


    
    return 0;
}