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
// https://atcoder.jp/contests/abc307/tasks/abc307_e

int main(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = 1;
    dp[1][1] = m-1;
    rep(i, 2, n){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = (dp[i-1][0]*(m-1)+(dp[i-1][1])*(m-2))%MOD;
    }

    cout << (dp[n-1][1]*m)%MOD << endl;
    return 0;
}