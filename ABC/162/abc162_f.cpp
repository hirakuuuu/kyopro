#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc162/tasks/abc162_f

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    if(n%2 == 0){
        ll ans = -(1LL<<60);
        vector<vector<ll>> dp(n+1, vector<ll>(2, -(1LL<<60)));
        dp[0][1] = a[0];
        dp[1][0] = a[1];
        rep(i, 0, n){
            if(i+2 < n){
                rep(j, 0, 2){
                    if(dp[i][j] != -(1LL<<60)) chmax(dp[i+2][j], dp[i][j]+a[i+2]);
                }
            }
            if(i+3 < n){
                rep(j, 1, 2){
                    if(dp[i][j] != -(1LL<<60)) chmax(dp[i+3][j-1], dp[i][j]+a[i+3]);
                }
            }
            // rep(j, 0, 3){
            //     cout << dp[i][j] << ' ';
            // }
            // cout << endl;
        }

        chmax(ans, dp[n-2][1]);
        chmax(ans, dp[n-1][0]);
        cout << ans << endl;
    }else{
        ll ans = -(1LL<<60);
        vector<vector<ll>> dp(n+1, vector<ll>(3, -(1LL<<60)));
        dp[0][2] = a[0];
        dp[1][1] = a[1];
        dp[2][0] = a[2];
        rep(i, 0, n){
            if(i+2 < n){
                rep(j, 0, 3){
                    if(dp[i][j] != -(1LL<<60)) chmax(dp[i+2][j], dp[i][j]+a[i+2]);
                }
            }
            if(i+3 < n){
                rep(j, 1, 3){
                    if(dp[i][j] != -(1LL<<60)) chmax(dp[i+3][j-1], dp[i][j]+a[i+3]);
                }
            }
            if(i+4 < n){
                rep(j, 2, 3){
                    if(dp[i][j] != -(1LL<<60)) chmax(dp[i+4][j-2], dp[i][j]+a[i+4]);
                }
            }
            // rep(j, 0, 3){
            //     cout << dp[i][j] << ' ';
            // }
            // cout << endl;
        }

        chmax(ans, dp[n-3][2]);
        chmax(ans, dp[n-2][1]);
        chmax(ans, dp[n-1][0]);
        cout << ans << endl;
    }

    
    return 0;
}