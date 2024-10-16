#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

/*
LCS は DP 
逆順にした文字列とのLCSは、回文だけを考えればよい

*/

int main(){
    string s; cin >> s;
    int n = (int)s.size();
    int k; cin >> k;

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(k+1)));
    rep(i, 0, n){
        rep(x, 0, k+1){
            dp[i][i+1][x] = 1;
        }
    }
    rep(range, 2, n+1){
        rep(l, 0, n-range+1){
            int r = l+range;
            rep(x, 0, k+1){
                if(x >= 1) chmax(dp[l][r][x], dp[l][r][x-1]);
                chmax(dp[l][r][x], max(dp[l+1][r][x], dp[l][r-1][x]));
                if(s[l] == s[r-1]) chmax(dp[l][r][x], dp[l+1][r-1][x]+2);
                else if(x >= 1) chmax(dp[l][r][x], dp[l+1][r-1][x-1]+2);
            }
        }
    }
    cout << dp[0][n][k] << endl;
    return 0;
}