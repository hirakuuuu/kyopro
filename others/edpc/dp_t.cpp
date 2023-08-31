#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
constexpr ll MOD = 1000000007;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/dp/tasks/dp_t

int main(){
    int n; cin >> n;
    string s; cin >> s;

    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    dp[1][1] = 1;
    rep(i, 2, n+1){

        vector<ll> dp_(n+1);
        dp_[1] = dp[i-1][1];
        rep(j, 2, i+1){
            dp_[j] = dp_[j-1]+dp[i-1][j];
            dp_[j] %= MOD;
        }

        rep(j, 1, i+1){
            if(s[i-2] == '<') dp[i][j] += dp_[j-1];
            else dp[i][j] += dp_[i]-dp_[j-1];
            if(dp[i][j] < 0) dp[i][j] += MOD;
            dp[i][j] %= MOD;
        }

    }

    ll ans = 0;
    rep(i, 1, n+1){
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << endl;


    
    return 0;
}