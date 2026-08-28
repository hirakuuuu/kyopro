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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, IINF));
    rep(i, 0, m+1) dp[0][i] = i;
    rep(i, 0, n+1) dp[i][0] = i;
    rep(i, 1, n+1){
        rep(j, 1, m+1){
            if(s[i-1] == t[j-1]) chmin(dp[i][j], dp[i-1][j-1]);
            chmin(dp[i][j], dp[i][j-1]+1);
            chmin(dp[i][j], dp[i-1][j]+1);
            chmin(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    cout << dp[n][m] << endl;
    
    
    return 0;
}