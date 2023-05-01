#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc197/tasks/abc197_e

int main(){
    int n; cin >> n;
    vector<ll> x(n+1), c(n+1);
    rep(i, 0, n) cin >> x[i] >> c[i];
    c[n] = n+1;

    vector<bool> exist(n+2);
    vector<ll> max_x(n+2), min_x(n+2);

    rep(i, 0, n+1){
        if(exist[c[i]]){
            chmax(max_x[c[i]], x[i]);
            chmin(min_x[c[i]], x[i]);
        }else{
            exist[c[i]] = true;
            max_x[c[i]] = x[i];
            min_x[c[i]] = x[i];
        }
    }

    vector<ll> pos(2);
    vector<vector<ll>> dp(n+2, vector<ll>(2));
    rep(i, 1, n+2){
        if(!exist[i]){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
        }else{
            dp[i][0] = min(dp[i-1][0]+abs(pos[0]-max_x[i])+(max_x[i]-min_x[i]), dp[i-1][1]+abs(pos[1]-max_x[i])+(max_x[i]-min_x[i]));
            dp[i][1] = min(dp[i-1][0]+abs(pos[0]-min_x[i])+(max_x[i]-min_x[i]), dp[i-1][1]+abs(pos[1]-min_x[i])+(max_x[i]-min_x[i]));;
            pos[0] = min_x[i];
            pos[1] = max_x[i];
        }

        // cout << i << ' ';
        // rep(j, 0, 2){
        //     cout << dp[i][j] << ' ';
        // }
        // cout << endl;
    }
    cout << min(dp[n+1][0], dp[n+1][1]) << endl;
    
    return 0;
}