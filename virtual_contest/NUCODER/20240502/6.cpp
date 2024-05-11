#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, m; cin >> n >> m;
    vector<int> s(n), t(m);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, m) cin >> t[i];
    vector<vector<mint>> dp(n+1, vector<mint>(m+1, 1));
    rep(i, 0, n){
        rep(j, 0, m){
            dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1]-dp[i][j];
            if(s[i] == t[j]) dp[i+1][j+1] += dp[i][j];
        }
    }
    // rep(i, 0, n+1){
    //     rep(j, 0, m+1){
    //         cout << dp[i][j].val() << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m].val() << endl;

    
    return 0;
}