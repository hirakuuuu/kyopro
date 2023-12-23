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
// https://atcoder.jp/contests/abc245/tasks/abc245_c

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = dp[0][1] = 1;
    rep(i, 1, n){
        if(dp[i-1][0]){
            if(abs(a[i-1]-a[i]) <= k) dp[i][0] = 1;
            if(abs(a[i-1]-b[i]) <= k) dp[i][1] = 1;
        }
        if(dp[i-1][1]){
            if(abs(b[i-1]-a[i]) <= k) dp[i][0] = 1;
            if(abs(b[i-1]-b[i]) <= k) dp[i][1] = 1;
        }
    }

    if(dp[n-1][0] || dp[n-1][1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}