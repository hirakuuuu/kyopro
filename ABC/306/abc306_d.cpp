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
// https://atcoder.jp/contests/abc306/tasks/abc306_d

int main(){
    int n; cin >> n;
    vector<vector<ll>> dp(n+1, vector<ll>(2, -INF));
    dp[0][0] = 0;
    rep(i, 1, n+1){
        ll x, y; cin >> x >> y;
        if(x == 0){
            dp[i][0] = max({dp[i-1][0], dp[i-1][0]+y, dp[i-1][1] + y});
            dp[i][1] = dp[i-1][1];
        }else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max({dp[i-1][0]+y, dp[i-1][1]});
        }
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
    
    return 0;
}